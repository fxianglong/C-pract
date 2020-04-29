#include <iostream>
#include <mutex>
#include <thread>
using namespace std;


//// 饿汉模式
//// 优点：简单
//// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//
//private:
//	// 构造函数私有
//	Singleton(){};
//
//	// C++98 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	// or
//
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//
//	static Singleton m_instance;
//};
//
//Singleton Singleton::m_instance;  // 在程序入口之前就完成单例对象的初始化



//// 懒汉
//// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//// 缺点：复杂

//
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//
//	// 实现一个内嵌垃圾回收类    
//	class CGarbo {
//	public:
//		~CGarbo(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//
//private:
//	// 构造函数私有
//	Singleton(){};
//
//	// 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx;            //互斥锁
//};
//
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//
//}
//// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//
//	t1.join();
//	t2.join();
//
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//}



//typedef void(*FUNC)();
//int DoSomething(int i)
//{
//	cout << "DoSomething" << endl;
//	return 0;
//}
//
//void Test()
//{
//	//
//	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
//	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
//	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
//	//
//	FUNC f = reinterpret_cast< FUNC>(DoSomething);
//	f();
//}
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}



template <int inst>
class __malloc_alloc_template{
private:
	static void *oom_malloc(size_t);
public:
	static void* allocate(size_t n)
	{
		// 申请空间成功，直接返回，失败交由oom_malloc处理
		void *result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);
		return result;
	}
	// 对free的封装
	static void deallocate(void *p, size_t /* n */)
	{
		free(p);
	}

	// 模拟set_new_handle
	// 该函数的参数为函数指针，返回值类型也为函数指针
	// void (*    set_malloc_handler( void (*f)() ) )()
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return(old);
	}
};

template <int inst>
void * __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void(*my_malloc_handler)();
	void *result;
	for (;;)
	{
		// 检测用户是否设置空间不足应对措施，如果没有设置，抛异常，模式new的方式
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}

		// 如果设置，执行用户提供的空间不足应对措施
		(*my_malloc_handler)();

		// 继续申请空间，可能就会申请成功
		result = malloc(n);
		if (result)
			return(result);
	}
}

typedef __malloc_alloc_template<0> malloc_alloc;



template <int inst>
class __default_alloc_template
{
private:
	enum { __ALIGN = 8 };     // 如果用户所需内存不是8的整数倍，向上对齐到8的整数倍
	enum { __MAX_BYTES = 128 };   // 大小内存块的分界线
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };  // 采用哈希桶保存小块内存时所需桶的个
	数

		// 如果用户所需内存块不是8的整数倍，向上对齐到8的整数倍
		static size_t ROUND_UP(size_t bytes)
	{
			return (((bytes)+__ALIGN - 1) & ~(__ALIGN - 1));
		}

private:
	// 用联合体来维护链表结构
	union obj
	{
		union obj * free_list_link;
		char client_data[1];    /* The client sees this.        */
	};

private:
	static obj *  free_list[__NFREELISTS];
	// 哈希函数，根据用户提供字节数找到对应的桶号
	static  size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes)+__ALIGN - 1) / __ALIGN - 1);
	}

	// start_free与end_free用来标记内存池中大块内存的起始与末尾位置
	static char *start_free;
	static char *end_free;

	// 用来记录该空间配置器已经想系统索要了多少的内存块
	static size_t heap_size;

	// ...
};


// 函数功能：向空间配置器索要空间
// 参数n: 用户所需空间字节数
// 返回值：返回空间的首地址
static void * allocate(size_t n)
{
	obj * __VOLATILE * my_free_list;
	obj * __RESTRICT result;

	// 检测用户所需空间释放超过128(即是否为小块内存)
	if (n > (size_t)__MAX_BYTES)
	{
		// 不是小块内存交由一级空间配置器处理
		return (malloc_alloc::allocate(n));
	}

	// 根据用户所需字节找到对应的桶号
	my_free_list = free_list + FREELIST_INDEX(n);
	result = *my_free_list;

	// 如果该桶中没有内存块时，向该桶中补充空间
	if (result == 0)
	{
		// 将n向上对齐到8的整数被，保证向桶中补充内存块时，内存块一定是8的整数倍
		void *r = refill(ROUND_UP(n));
		return r;
	}

	// 维护桶中剩余内存块的链式关系
	*my_free_list = result->free_list_link;
	return (result);
};


// 函数功能：向哈希桶中补充空间
// 参数n：小块内存字节数
// 返回值：首个小块内存的首地址
template <int inst>
void* __default_alloc_template<inst>::refill(size_t n)
{
	// 一次性向内存池索要20个n字节的小块内存
	int nobjs = 20;
	char * chunk = chunk_alloc(n, nobjs);

	obj ** my_free_list;
	obj *result;
	obj *current_obj, *next_obj;
	int i;

	// 如果只要了一块，直接返回给用户使用
	if (1 == nobjs)
		return(chunk);

	// 找到对应的桶号
	my_free_list = free_list + FREELIST_INDEX(n);

	// 将第一块返回值用户，其他块连接在对应的桶中
	// 注：此处代码逻辑比较简单，但标准库实现稍微有点复杂，同学们可以自己实现
	result = (obj *)chunk;
	*my_free_list = next_obj = (obj *)(chunk + n);
	for (i = 1;; i++)
	{
		current_obj = next_obj;
		next_obj = (obj *)((char *)next_obj + n);
		if (nobjs - 1 == i)
		{
			current_obj->free_list_link = 0;
			break;
		}
		else
		{
			current_obj->free_list_link = next_obj;
		}
	}

	return(result);
}


template <int inst>
char* __default_alloc_template<inst>::chunk_alloc(size_t size, int& nobjs)
{
	// 计算nobjs个size字节内存块的总大小以及内存池中剩余空间总大小
	char * result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;

	// 如果内存池可以提供total_bytes字节，返回
	if (bytes_left >= total_bytes)
	{
		result = start_free;
		start_free += total_bytes;
		return(result);
	}
	else if (bytes_left >= size)
	{
		// nobjs块无法提供，但是至少可以提供1块size字节内存块，提供后返回
		nobjs = bytes_left / size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return(result);
	}
	else
	{
		// 内存池空间不足，连一块小块内存都不能提供
		// 向系统堆求助，往内存池中补充空间
		// 计算向内存中补充空间大小：本次空间总大小两倍 + 向系统申请总大小/16
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);

		// 如果内存池有剩余空间(该空间一定是8的整数倍)，将该空间挂到对应哈希桶中
		if (bytes_left > 0)
		{
			// 找对用哈希桶，将剩余空间挂在其上
			obj ** my_free_list = free_list + FREELIST_INDEX(bytes_left);
			((obj *)start_free)->free_list_link = *my_free_list;
			*my_ree_list = (obj *)start_free;
		}

		// 通过系统堆向内存池补充空间，如果补充成功，递归继续分配
		start_free = (char *)malloc(bytes_to_get);
		if (0 == start_free)
		{
			// 通过系统堆补充空间失败，在哈希桶中找是否有没有使用的较大的内存块
			int i;
			obj ** my_free_list, *p;
			for (i = size; i <= __MAX_BYTES; i += __ALIGN)
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;

				// 如果有，将该内存块补充进内存池，递归继续分配
				if (0 != p)
				{
					*my_free_list = p->free_list_link;
					start_free = (char *)p;
					end_free = start_free + i;
					return(chunk_alloc(size, nobjs));
				}
			}

			// 只能向一级空间配置器求助
			// 注意：此处一定要将end_free置空，因为一级空间配置器一旦抛异常就会出问题
			end_free = 0;
			start_free = (char *)malloc_alloc::allocate(bytes_to_get);
		}

		// 通过系统堆向内存池补充空间成功，更新信息并继续分配
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return(chunk_alloc(size, nobjs));
	}
}



// 函数功能：用户将空间归还给空间配置器
// 参数：p空间首地址   n空间总大小
static void deallocate(void *p, size_t n)
{
	obj *q = (obj *)p;
	obj ** my_free_list;

	// 如果空间不是小块内存，交给一级空间配置器回收
	if (n > (size_t)__MAX_BYTES)
	{
		malloc_alloc::deallocate(p, n);
		return;
	}

	// 找到对应的哈希桶，将内存挂在哈希桶中
	my_free_list = free_list + FREELIST_INDEX(n);
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}


// T: 元素类型
// Alloc: 空间配置器
// 注意：该类只负责申请与归还对象的空间，不否则空间中对象的构造与析构
template<class T, class Alloc>
class simple_alloc
{
public:
	// 申请n个T类型对象大小的空间
	static T *allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::allocate(n * sizeof (T));
	}

	// 申请一个T类型对象大小的空间
	static T *allocate(void)
	{
		return (T*)Alloc::allocate(sizeof (T));
	}

	// 释放n个T类型对象大小的空间
	static void deallocate(T *p, size_t n)
	{
		if (0 != n)
			Alloc::deallocate(p, n * sizeof (T));
	}

	// 释放一个T类型对象大小的空间
	static void deallocate(T *p)
	{
		Alloc::deallocate(p, sizeof (T));
	}
};


template <class T, class Alloc = alloc>
class list
{
	// ...
	// 实例化空间配置器
	typedef simple_alloc<list_node, Alloc> list_node_allocator;
	// ...

protected:
	link_type get_node()
	{
		// 调用空间配置器接口先申请节点的空间
		return list_node_allocator::allocate();
	}

	// 将节点归还给空间配置器
	void put_node(link_type p)
	{
		list_node_allocator::deallocate(p);
	}

	// 创建节点：1. 申请空间  2. 完成节点构造
	link_type create_node(const T& x)

	{
		link_type p = get_node();
		construct(&p->data, x);
		return p;
	}

	// 销毁节点： 1. 调用析构函数清理节点中资源  2. 将节点空间归还给空间配置器
	void destroy_node(link_type p)
	{
		destroy(&p->data);
		put_node(p);
	}

	// ...
	iterator insert(iterator position, const T& x)
	{
		link_type tmp = create_node(x);
		tmp->next = position.node;
		tmp->prev = position.node->prev;
		(link_type(position.node->prev))->next = tmp;
		position.node->prev = tmp;
		return tmp;
	}

	iterator erase(iterator position)
	{
		link_type next_node = link_type(position.node->next);
		link_type prev_node = link_type(position.node->prev);
		prev_node->next = next_node;
		next_node->prev = prev_node;
		destroy_node(position.node);
		return iterator(next_node);
	}

	// ...
};