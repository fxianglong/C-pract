#pragma once 

#ifdef _WIN32
//Windows头文件
#include<iostream>
#include<vector>
#include<stdint.h>
#include<fstream>
#include<boost/filesystem.hpp>
#include<WS2tcpip.h>
#include<IPHlpApi.h>//获取网卡信息接口的头文件
#pragma comment(lib,"Iphlpapi.lib")//获取网卡信息的库
#pragma comment(lib,"ws2_32.lib")
#else
//Linux头文件
#endif

class FileUtil{
public:
	static bool Write(const std::string &name, const std::string &body, int64_t offset=0){

		std::ofstream ofs(name);
		if (ofs.is_open() == false){
			std::cerr << "打开文件失败";
			return false;
		}
		ofs.seekp(offset, std::ios::beg);//读写位置跳转到相对于文件起始位置开始偏移offset的偏移量
		ofs.write(&body[0], body.size());
		if (ofs.good() == false){
				std::cerr << "向文件写入数据失败\n";
				ofs.close();
				return false;
		}
		ofs.close();
		return true;
	}
	//指针参数表示这是一个输出型参数
	//const &表示这是一个输入型参数
	//& 表示这是一个输出输入型参数
	static bool Read(const std::string &name, std::string *body){
		std::ifstream ifs(name);
		if (ifs.is_open() == false){
			std::cerr << "打开文件失败";
			return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		ifs.read(&(*body)[0], filesize);
		/*if (ifs.good() == false)
		{
			std::cerr << "读取文件失败";
			ifs.close();
			return false;
		}*/
		ifs.close();
		return true;
	}
};

class Adapter{
public:
	uint32_t _ip_addr;//网卡上的IP地址
	uint32_t _mask_addr;//网卡上的子网掩码
};

class AdapterUtil
{
#ifdef _WIN32//windows下的获取网卡信息的借口
public:
	static bool GetAllAdapter(std::vector<Adapter> *list){
		//PIP_ADAPTER_INFO存放网卡信息
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();//开辟一块网卡信息结构的空间
		//获取网卡信息可能会失败，因为空间不足，因此有一个输出型参数
		uint64_t all_adapter_size = sizeof(p_adapters);
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW){//缓冲区内存不足
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		}
		while (p_adapters)
		{
			Adapter adapter;
			inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);//将一个字符串点分十进制的IP地址转换为网络字节序的IP地址
			inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._ip_addr);
			adapter._ip_addr = inet_addr(p_adapters->IpAddressList.IpAddress.String);
			adapter._mask_addr = inet_addr(p_adapters->IpAddressList.IpMask.String);
			if (adapter._ip_addr != 0)//因为有些网卡并没有启用
			{
				list->push_back(adapter);//将网卡信息添加到vector
				/*std::cout << "网卡名称" << p_adapters->AdapterName << std::endl;
				std::cout << "网卡描述" << p_adapters->Description << std::endl;
				std::cout << "网卡IP地址" << p_adapters->IpAddressList.IpAddress.String << std::endl;
				std::cout << "子网掩码" << p_adapters->IpAddressList.IpMask.String << std::endl;
				std::cout << std::endl;*/
			}
			p_adapters = p_adapters->Next;

		}
		delete p_adapters;
		return true;
	}
#else//Linux下的获取网卡信息
	bool GetAllAdapter(std::vector<Adapter> *list){
		return true;
	}
#endif
};