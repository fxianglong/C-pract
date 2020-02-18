#include<boost/filesystem.hpp>
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
	Client cli;
	cli.Start();
}
int main(int argc,char*argv[])
{
	//在主线程中要运行客户端模块以及服务端模块
	//创建于一个县城运行客户端模块，主线程运行服务端模块

	std::thread thr_client(ClientRun);//若客户端运行的时候，服务端还没有启动

	Sever srv;
	srv.Start();
	return 0; 

}