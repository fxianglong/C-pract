#include"client.hpp"
#include"util.hpp"
#include"httplib.h"
//void helloworld(const httplib::Request &req, httplib::Response &rsp)
//{
//	rsp.set_content("<html><h1>HelloWorld<h1><html>", "text/html");
//}
//void Scandir()
//{
//	const char *ptr = "./";
//	boost::filesystem::directory_iterator begin(ptr);//����һ��Ŀ¼����������
//	boost::filesystem::directory_iterator end;
//	for (; begin != end; ++begin){
//		
//		if (boost::filesystem::is_directory(begin->status()))//��ǰ�ļ�Ŀ¼״̬��Ϣ
//		{
//			std::cout << begin->path().string() << "��һ��Ŀ¼\n";//��ȡ��ǰ�����ļ���
//		}
//		else
//		{
//			std::cout << begin->path().string() << "��һ����ͨ�ļ�\n";
//		}
//	}
//}
void ClientRun()
{
	Sleep(1);
	Client cli;
	cli.Start();
}
int main(int argc,char*argv[])
{
	std::thread thr_client(ClientRun);
	Sever srv;
	srv.Start();
	return 0; 

}