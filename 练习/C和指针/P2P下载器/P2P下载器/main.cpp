
#include"util.hpp"
#include"httplib.h"
void helloworld(const httplib::Request &req, httplib::Response &rsp)
{
	rsp.set_content("<html><h1>HelloWorld<h1><html>", "text/html");
}
void Scandir()
{
	const char *ptr = "./";
	boost::filesystem::directory_iterator begin(ptr);//定义一个目录迭代器对象
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin){
		
		if (boost::filesystem::is_directory(begin->status()))//当前文件目录状态信息
		{
			std::cout << begin->path().string() << "是一个目录\n";//获取当前迭代文件名
		}
		else
		{
			std::cout << begin->path().string() << "是一个普通文件\n";
		}
	}
}
int main()
{
	/*std::vector<Adapter> list;
	AdapterUtil::GetAllAdapter(&list);*/
	//httplib::Server srv;
	//srv.Get("/", helloworld);
	//srv.listen("0.0.0.0", 9000);//本机任一IP地址
	//system("pause");
	Scandir();
	Sleep(76545678);
	return 0; 

}