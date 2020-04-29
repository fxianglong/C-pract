#include <iostream>
#include <mutex>
#include <thread>
using namespace std;


//// ����ģʽ
//// �ŵ㣺��
//// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//
//private:
//	// ���캯��˽��
//	Singleton(){};
//
//	// C++98 ������
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
//Singleton Singleton::m_instance;  // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��



//// ����
//// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
//// ȱ�㣺����

//
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
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
//	// ʵ��һ����Ƕ����������    
//	class CGarbo {
//	public:
//		~CGarbo(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//
//private:
//	// ���캯��˽��
//	Singleton(){};
//
//	// ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//
//	static Singleton* m_pInstance; // ��������ָ��
//	static mutex m_mtx;            //������
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
//// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
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
//	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
//	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
//	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
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
		// ����ռ�ɹ���ֱ�ӷ��أ�ʧ�ܽ���oom_malloc����
		void *result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);
		return result;
	}
	// ��free�ķ�װ
	static void deallocate(void *p, size_t /* n */)
	{
		free(p);
	}

	// ģ��set_new_handle
	// �ú����Ĳ���Ϊ����ָ�룬����ֵ����ҲΪ����ָ��
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
		// ����û��Ƿ����ÿռ䲻��Ӧ�Դ�ʩ�����û�����ã����쳣��ģʽnew�ķ�ʽ
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}

		// ������ã�ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ
		(*my_malloc_handler)();

		// ��������ռ䣬���ܾͻ�����ɹ�
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
	enum { __ALIGN = 8 };     // ����û������ڴ治��8�������������϶��뵽8��������
	enum { __MAX_BYTES = 128 };   // ��С�ڴ��ķֽ���
	enum { __NFREELISTS = __MAX_BYTES / __ALIGN };  // ���ù�ϣͰ����С���ڴ�ʱ����Ͱ�ĸ�
	��

		// ����û������ڴ�鲻��8�������������϶��뵽8��������
		static size_t ROUND_UP(size_t bytes)
	{
			return (((bytes)+__ALIGN - 1) & ~(__ALIGN - 1));
		}

private:
	// ����������ά������ṹ
	union obj
	{
		union obj * free_list_link;
		char client_data[1];    /* The client sees this.        */
	};

private:
	static obj *  free_list[__NFREELISTS];
	// ��ϣ�����������û��ṩ�ֽ����ҵ���Ӧ��Ͱ��
	static  size_t FREELIST_INDEX(size_t bytes)
	{
		return (((bytes)+__ALIGN - 1) / __ALIGN - 1);
	}

	// start_free��end_free��������ڴ���д���ڴ����ʼ��ĩβλ��
	static char *start_free;
	static char *end_free;

	// ������¼�ÿռ��������Ѿ���ϵͳ��Ҫ�˶��ٵ��ڴ��
	static size_t heap_size;

	// ...
};


// �������ܣ���ռ���������Ҫ�ռ�
// ����n: �û�����ռ��ֽ���
// ����ֵ�����ؿռ���׵�ַ
static void * allocate(size_t n)
{
	obj * __VOLATILE * my_free_list;
	obj * __RESTRICT result;

	// ����û�����ռ��ͷų���128(���Ƿ�ΪС���ڴ�)
	if (n > (size_t)__MAX_BYTES)
	{
		// ����С���ڴ潻��һ���ռ�����������
		return (malloc_alloc::allocate(n));
	}

	// �����û������ֽ��ҵ���Ӧ��Ͱ��
	my_free_list = free_list + FREELIST_INDEX(n);
	result = *my_free_list;

	// �����Ͱ��û���ڴ��ʱ�����Ͱ�в���ռ�
	if (result == 0)
	{
		// ��n���϶��뵽8������������֤��Ͱ�в����ڴ��ʱ���ڴ��һ����8��������
		void *r = refill(ROUND_UP(n));
		return r;
	}

	// ά��Ͱ��ʣ���ڴ�����ʽ��ϵ
	*my_free_list = result->free_list_link;
	return (result);
};


// �������ܣ����ϣͰ�в���ռ�
// ����n��С���ڴ��ֽ���
// ����ֵ���׸�С���ڴ���׵�ַ
template <int inst>
void* __default_alloc_template<inst>::refill(size_t n)
{
	// һ�������ڴ����Ҫ20��n�ֽڵ�С���ڴ�
	int nobjs = 20;
	char * chunk = chunk_alloc(n, nobjs);

	obj ** my_free_list;
	obj *result;
	obj *current_obj, *next_obj;
	int i;

	// ���ֻҪ��һ�飬ֱ�ӷ��ظ��û�ʹ��
	if (1 == nobjs)
		return(chunk);

	// �ҵ���Ӧ��Ͱ��
	my_free_list = free_list + FREELIST_INDEX(n);

	// ����һ�鷵��ֵ�û��������������ڶ�Ӧ��Ͱ��
	// ע���˴������߼��Ƚϼ򵥣�����׼��ʵ����΢�е㸴�ӣ�ͬѧ�ǿ����Լ�ʵ��
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
	// ����nobjs��size�ֽ��ڴ����ܴ�С�Լ��ڴ����ʣ��ռ��ܴ�С
	char * result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;

	// ����ڴ�ؿ����ṩtotal_bytes�ֽڣ�����
	if (bytes_left >= total_bytes)
	{
		result = start_free;
		start_free += total_bytes;
		return(result);
	}
	else if (bytes_left >= size)
	{
		// nobjs���޷��ṩ���������ٿ����ṩ1��size�ֽ��ڴ�飬�ṩ�󷵻�
		nobjs = bytes_left / size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return(result);
	}
	else
	{
		// �ڴ�ؿռ䲻�㣬��һ��С���ڴ涼�����ṩ
		// ��ϵͳ�����������ڴ���в���ռ�
		// �������ڴ��в���ռ��С�����οռ��ܴ�С���� + ��ϵͳ�����ܴ�С/16
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);

		// ����ڴ����ʣ��ռ�(�ÿռ�һ����8��������)�����ÿռ�ҵ���Ӧ��ϣͰ��
		if (bytes_left > 0)
		{
			// �Ҷ��ù�ϣͰ����ʣ��ռ��������
			obj ** my_free_list = free_list + FREELIST_INDEX(bytes_left);
			((obj *)start_free)->free_list_link = *my_free_list;
			*my_ree_list = (obj *)start_free;
		}

		// ͨ��ϵͳ�����ڴ�ز���ռ䣬�������ɹ����ݹ��������
		start_free = (char *)malloc(bytes_to_get);
		if (0 == start_free)
		{
			// ͨ��ϵͳ�Ѳ���ռ�ʧ�ܣ��ڹ�ϣͰ�����Ƿ���û��ʹ�õĽϴ���ڴ��
			int i;
			obj ** my_free_list, *p;
			for (i = size; i <= __MAX_BYTES; i += __ALIGN)
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;

				// ����У������ڴ�鲹����ڴ�أ��ݹ��������
				if (0 != p)
				{
					*my_free_list = p->free_list_link;
					start_free = (char *)p;
					end_free = start_free + i;
					return(chunk_alloc(size, nobjs));
				}
			}

			// ֻ����һ���ռ�����������
			// ע�⣺�˴�һ��Ҫ��end_free�ÿգ���Ϊһ���ռ�������һ�����쳣�ͻ������
			end_free = 0;
			start_free = (char *)malloc_alloc::allocate(bytes_to_get);
		}

		// ͨ��ϵͳ�����ڴ�ز���ռ�ɹ���������Ϣ����������
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return(chunk_alloc(size, nobjs));
	}
}



// �������ܣ��û����ռ�黹���ռ�������
// ������p�ռ��׵�ַ   n�ռ��ܴ�С
static void deallocate(void *p, size_t n)
{
	obj *q = (obj *)p;
	obj ** my_free_list;

	// ����ռ䲻��С���ڴ棬����һ���ռ�����������
	if (n > (size_t)__MAX_BYTES)
	{
		malloc_alloc::deallocate(p, n);
		return;
	}

	// �ҵ���Ӧ�Ĺ�ϣͰ�����ڴ���ڹ�ϣͰ��
	my_free_list = free_list + FREELIST_INDEX(n);
	q->free_list_link = *my_free_list;
	*my_free_list = q;
}


// T: Ԫ������
// Alloc: �ռ�������
// ע�⣺����ֻ����������黹����Ŀռ䣬������ռ��ж���Ĺ���������
template<class T, class Alloc>
class simple_alloc
{
public:
	// ����n��T���Ͷ����С�Ŀռ�
	static T *allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::allocate(n * sizeof (T));
	}

	// ����һ��T���Ͷ����С�Ŀռ�
	static T *allocate(void)
	{
		return (T*)Alloc::allocate(sizeof (T));
	}

	// �ͷ�n��T���Ͷ����С�Ŀռ�
	static void deallocate(T *p, size_t n)
	{
		if (0 != n)
			Alloc::deallocate(p, n * sizeof (T));
	}

	// �ͷ�һ��T���Ͷ����С�Ŀռ�
	static void deallocate(T *p)
	{
		Alloc::deallocate(p, sizeof (T));
	}
};


template <class T, class Alloc = alloc>
class list
{
	// ...
	// ʵ�����ռ�������
	typedef simple_alloc<list_node, Alloc> list_node_allocator;
	// ...

protected:
	link_type get_node()
	{
		// ���ÿռ��������ӿ�������ڵ�Ŀռ�
		return list_node_allocator::allocate();
	}

	// ���ڵ�黹���ռ�������
	void put_node(link_type p)
	{
		list_node_allocator::deallocate(p);
	}

	// �����ڵ㣺1. ����ռ�  2. ��ɽڵ㹹��
	link_type create_node(const T& x)

	{
		link_type p = get_node();
		construct(&p->data, x);
		return p;
	}

	// ���ٽڵ㣺 1. ����������������ڵ�����Դ  2. ���ڵ�ռ�黹���ռ�������
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