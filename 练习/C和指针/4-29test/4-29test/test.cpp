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



//template <int inst>
//class __malloc_alloc_template{
//private:
//	static void *oom_malloc(size_t);
//public:
//	static void* allocate(size_t n)
//	{
//		// ����ռ�ɹ���ֱ�ӷ��أ�ʧ�ܽ���oom_malloc����
//		void *result = malloc(n);
//		if (0 == result)
//			result = oom_malloc(n);
//		return result;
//	}
//	// ��free�ķ�װ
//	static void deallocate(void *p, size_t /* n */)
//	{
//		free(p);
//	}
//
//	// ģ��set_new_handle
//	// �ú����Ĳ���Ϊ����ָ�룬����ֵ����ҲΪ����ָ��
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
//		// ����û��Ƿ����ÿռ䲻��Ӧ�Դ�ʩ�����û�����ã����쳣��ģʽnew�ķ�ʽ
//		my_malloc_handler = __malloc_alloc_oom_handler;
//		if (0 == my_malloc_handler)
//		{
//			__THROW_BAD_ALLOC;
//		}
//
//		// ������ã�ִ���û��ṩ�Ŀռ䲻��Ӧ�Դ�ʩ
//		(*my_malloc_handler)();
//
//		// ��������ռ䣬���ܾͻ�����ɹ�
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