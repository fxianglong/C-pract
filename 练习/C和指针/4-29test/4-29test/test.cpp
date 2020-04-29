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



//template <int inst>
//class __malloc_alloc_template{
//private:
//	static void *oom_malloc(size_t);
//public:
//	static void* allocate(size_t n)
//	{
//		// 申请空间成功，直接返回，失败交由oom_malloc处理
//		void *result = malloc(n);
//		if (0 == result)
//			result = oom_malloc(n);
//		return result;
//	}
//	// 对free的封装
//	static void deallocate(void *p, size_t /* n */)
//	{
//		free(p);
//	}
//
//	// 模拟set_new_handle
//	// 该函数的参数为函数指针，返回值类型也为函数指针
//	// void (*    set_malloc_handler( void (*f)() ) )()
//	static void(*set_malloc_handler(void(*f)()))()
//	{
//		void(*old)() = __malloc_alloc_oom_handler;
//		__malloc_alloc_oom_handler = f;
//		return(old);
//	}
//};
//
//template <int inst>
//void * __malloc_alloc_template<inst>::oom_malloc(size_t n)
//{
//	void(*my_malloc_handler)();
//	void *result;
//	for (;;)
//	{
//		// 检测用户是否设置空间不足应对措施，如果没有设置，抛异常，模式new的方式
//		my_malloc_handler = __malloc_alloc_oom_handler;
//		if (0 == my_malloc_handler)
//		{
//			__THROW_BAD_ALLOC;
//		}
//
//		// 如果设置，执行用户提供的空间不足应对措施
//		(*my_malloc_handler)();
//
//		// 继续申请空间，可能就会申请成功
//		result = malloc(n);
//		if (result)
//			return(result);
//	}
//}
//
//typedef __malloc_alloc_template<0> malloc_alloc;



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