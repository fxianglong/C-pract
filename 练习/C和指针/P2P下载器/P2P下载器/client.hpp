#pragma once
#include<thread>
#include"util.hpp"
#include"httplib.h"
#define P2P_PORT 9000
#define MAX_IPBUFFER 16
#define SHARED_PATH "./sHARED"
class Host{
public:
	uint32_t _ip_addr;
	bool _pair_ret;//用于存放配对结果
};
class Client{
public:
	//主机配对的线程入口函数
	void HostPair(Host *host)
	{
		//1.组织http协议格式的请求数据
		//2.搭建一个tcp的客户端对象，将数据发送
		//3.等待服务器端的回复，并进行解析
		//4.
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);//将网络字节序转换为
		httplib::Client cli(buf, P2P_PORT);//实例化httplib客户端对象
		auto rsp = cli.Get("/hostpair");//向服务端发送资源为/hostpair的Get请求//如果连接建立失败Get会返回NULL
		if (rsp && rsp->status == 200){//判断响应结果是否正确
			host->_pair_ret = true;//重置主机匹配结构
		}
	}
	bool GetOnlineHost()//获取在线主机
	{
		//1.获取网卡信息，进而得到局域网中所有的IP地址列表
		std::vector<Adapter> list;
		AdapterUtil::GetAllAdapter(&list);
		//获取所有主机序号
		std::vector<Host> host_list;
		for (int i = 0; i < list.size(); i++)
		{
			uint32_t ip = list[i]._ip_addr;
			uint32_t mask = list[i]._mask_addr;
			//计算网络号
			uint32_t net = (ip & mask);
			//计算机最大主机号
			uint32_t max_host = (~ntohl(mask));//这个主机IP的计算应该使用小端主机号
			
			std::vector<bool> ret_list(max_host);
			for (int j = 1; j < max_host; j++)//得到所有的主机IP地址列表
			{
				uint32_t host_ip = net + j;
				Host host;
				host._ip_addr = htonl(host_ip);//将主机字节序转换为字符串字节序
				host._pair_ret = false;
				host_list.push_back(host);
			}
				//2.逐个对IP地址列表中的主机发送配对请求
		}
		std::vector<std::thread*> thr_list(host_list.size());
		for (int i = 0; i < host_list.size(); i++){
			thr_list[i] = new std::thread(&Client::HostPair, this, &host_list[i]);
		}
		for (int i = 0; i < host_list.size(); i++)
		{
			thr_list[i]->join();
			if (host_list[i]._pair_ret == true){
				_online_host.push_back(host_list[i]);
			}
			delete thr_list[i];
		}
		for (int i = 0; i < _online_host.size(); i++)
		{
			char buf[MAX_IPBUFFER] = { 0 };
			inet_ntop(AF_INET, &_online_host[i]._ip_addr, buf, MAX_IPBUFFER);
			std::cout <<"\t"<< buf << std::endl;
		}
		//3.若配对请求得到响应，则对应主机位在线主机，则将IP添加到_online_host列表中
		//4.打印在线主机列表，使用户选择
		std::cout << "请用户配对主机，获取共享文件列表";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		GetShareList(select_ip);

	}
	bool GetShareList(const std::string &host_ip)//获取文件列表
	{
		//向服务器发送一个文件列表获取请求
		//1.先发送请求
		//2.得到响应之后解析正文
		httplib::Client cli(host_ip ,P2P_PORT);
		auto rsp = cli.Get("/liat");
		if (rsp == NULL || rsp->status != 200)
		{
			std::cerr << "获取文件列表错误";
			return false;
		}
		std::cout << rsp->body<<std::endl;
		std::cout << "选择要下载的文件";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		DownloadFile(host_ip,filename);
		return true;
	}
	bool DownloadFile(const std::string &host_ip,const std::string &filename)//下载文件
	{
		//1.向服务端发送文件下载请求
		//2.得到响应结果，响应结果中的Body正文就是文件数据

		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Get(req_path);
		if (rsp == NULL || rsp.status != 200){
			std::cerr << "下载文件，获取响应信息失败\n";
			return false;
		}
		if (FileUtil::Write(filename, rsp->body) == false){
			std::cerr << "文件下载失败\n";
			return false;
		}
		return true;
	}
private:
	std::vector<Host> _online_host;
};
class Sever{
public:
	bool Start(){
		  //添加针对客户端请求的处理方式对应关系
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		_srv.Get("/download/.*",Download);//正则表达式.表示除/n/r之外的任意字符，*：表示匹配前边字符任意次
		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
}
private:
	static bool HostPair(const httplib::Request &req,httplib::Response &rsp){
		rsp.status = 200;
		return;
	}
	//获取共享文件列表--在主机上设置一个共享目录
	static bool ShareList(const httplib::Request &req, httplib::Response &rsp){
		boost::filesystem::directory_iterator begin(SHARED_PATH);//实例化目录迭代器
		boost::filesystem::directory_iterator end;
		//开始迭代目录
		for (; begin != end; ++begin){
			if (boost::filesystem::is_directory(begin->status())){
				//当前版本我们只获取普通文件名称，不做多层级目录的操作
				continue;
			}
			std::string name = begin->path().string();
			rsp.body += name + "\r\n";
		}
		rsp.status = 200;
		return;
	}
	static bool Download(const httplib::Request &req, httplib::Response &rsp){
		boost::filesystem::path req_path(req.path);
		std::string name = req_path.filename().string();
		std::string realpath = SHARED_PATH + '/' + name;//实际文件的路径应该是在共享文件的目录下
		if (!boost::filesystem::exists(realpath) || boost::filesystem::is_directory(realpath)){
			rsp.status = 404;
			return;
		}
		if (FileUtil::Read(name, &rsp.body) == false){
			rsp.status = 500;
			return;
		}
		rsp.status = 200;
		return;
	}
private:
	httplib::Server _srv;
};