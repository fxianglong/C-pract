//#include<iostream>
//#include<pthread.h>
//#include<unistd.h>
//using namespace std;
//const int i = 5;
//__thread int var = i;//���ַ�ʽЧ��һ��
////__thread int var=5;//
//void* worker1(void* arg);
//void* worker2(void* arg);
//int main(){
//	pthread_t pid1, pid2;
//	//__thread int temp=5;
//	static __thread  int temp = 10;//���κ����ڵ�static����
//	pthread_create(&pid1, NULL, worker1, NULL);
//	pthread_create(&pid2, NULL, worker2, NULL);
//	pthread_join(pid1, NULL);
//	pthread_join(pid2, NULL);
//	cout << temp << endl;//���10
//	return 0;
//}
//void* worker1(void* arg){
//	cout << ++var << endl;//��� 6
//}
//void* worker2(void* arg){
//	sleep(1);//�ȴ��߳�1�ı�varֵ����֤�Ƿ�Ӱ���߳�2
//	cout << ++var << endl;//���6
//}
//#include<iostream>
//#include<pthread.h>
//#include<unistd.h>
//using namespace std;
//const int i = 5;
//__thread int var = i;
//
//void* worker1(void* arg);
//void* worker2(void* arg);
//int main(){
//	pthread_t pid1, pid2;
//
//	static __thread  int temp = 10;
//	pthread_create(&pid1, NULL, worker1, NULL);
//	pthread_create(&pid2, NULL, worker2, NULL);
//	pthread_join(pid1, NULL);
//	pthread_join(pid2, NULL);
//	cout << temp << endl;
//	return 0;
//}
//void* worker1(void* arg){
//	cout << ++var << endl;
//}
//void* worker2(void* arg){
//	sleep(1);
//	cout << ++var << endl;
//}

//#include<iostream>
//#include <set>
//using namespace std;
//void TestSet()
//{
//	// ������array�е�Ԫ�ع���set
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0,3,3,3,3,3,3 };
//	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	cout << s.size() << endl;
//
//	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//
//	// ʹ�õ����������ӡset�е�Ԫ��
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	// set��ֵΪ3��Ԫ�س����˼���
//	cout << s.count(3) << endl;
//	s.insert(11);
//	s.erase(3);
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend()){
//		cout << *rit<<" ";
//		rit++;
//	}
//}
//int main()
//{
//	TestSet();
//	system("pause");
//	return 0;
//}

#include<iostream>
#include <string>
#include <map>
using namespace std;
void TestMap()
{
	map<string, string> m;

	// ��map�в���Ԫ�صķ�ʽ��
	// ����ֵ��<"peach","����">����map�У���pairֱ���������ֵ��
	m.insert(pair<string, string>("peach", "����"));

	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ��
	m.insert(make_pair("banan", "�㽶"));

	// ����operator[]��map�в���Ԫ��
	/*
	operator[]��ԭ���ǣ�
	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
	operator[]�������insert����ֵ��ֵ���е�value����
	*/
	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����
	m["apple"] = "ƻ��";

	// key������ʱ���쳣
	//m.at("waterme") = "ˮ����";
	cout << m.size() << endl;

	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��
	auto ret = m.insert(make_pair("peach", "��ɫ"));
	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
		ret.first->second << " ����ʧ��" << endl;

	// ɾ��keyΪ"apple"��Ԫ��
	m.erase("apple");

	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;
}


int main()
{
	TestMap();
	system("pause");
	return 0;
}