
#include"util.hpp"
#include"httplib.h"
void helloworld(const httplib::Request &req, httplib::Response &rsp)
{
	rsp.set_content("<html><h1>HelloWorld<h1><html>", "text/html");
}
void Scandir()
{
	const char *ptr = "./";
	boost::filesystem::directory_iterator begin(ptr);//����һ��Ŀ¼����������
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin){
		
		if (boost::filesystem::is_directory(begin->status()))//��ǰ�ļ�Ŀ¼״̬��Ϣ
		{
			std::cout << begin->path().string() << "��һ��Ŀ¼\n";//��ȡ��ǰ�����ļ���
		}
		else
		{
			std::cout << begin->path().string() << "��һ����ͨ�ļ�\n";
		}
	}
}
int main()
{
	/*std::vector<Adapter> list;
	AdapterUtil::GetAllAdapter(&list);*/
	//httplib::Server srv;
	//srv.Get("/", helloworld);
	//srv.listen("0.0.0.0", 9000);//������һIP��ַ
	//system("pause");
	Scandir();
	Sleep(76545678);
	return 0; 

}