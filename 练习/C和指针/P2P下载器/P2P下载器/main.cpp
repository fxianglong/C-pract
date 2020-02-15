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
//	boost::filesystem::directory_iterator begin(ptr);//定义一个目录迭代器对象
//	boost::filesystem::directory_iterator end;
//	for (; begin != end; ++begin){
//		
//		if (boost::filesystem::is_directory(begin->status()))//当前文件目录状态信息
//		{
//			std::cout << begin->path().string() << "是一个目录\n";//获取当前迭代文件名
//		}
//		else
//		{
//			std::cout << begin->path().string() << "是一个普通文件\n";
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