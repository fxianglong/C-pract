#pragma once//头文件仅包含一次
#ifdef _WIN32
//win头文件
#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<IPHlpApi.h>
#include<vector>
#include<stdint.h>
#pragma comment(lib, "Iphlpapi.lib")

#else
//Linux头文件

#endif
class Adapter{
public:
	uint32_t _ip_addr;//网卡上的IP地址
	uint32_t _mask_addr;//网卡上的子网掩码
};

class AdapterUtil{
#ifdef _WIN32
	//windows下的获取网卡信息实现
public:
	static bool GetAllAdapter(std::vector<Adapter>*list){
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
			//GetAdaptersInfo win下获取网卡及信息的借口--网卡信息有可能有多个，因此传入一个指针
		//获取网卡信息可能会失败，因此空间不足，因此有一个输出型参数，用于向用户返回到底有多少网卡
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		int ret = GetAdaptersInfo(p_adapters,(PULONG)all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW)//当前缓冲区溢出，缓冲区空间不足，因此重新给指针申请空间
		{
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			GetAdaptersInfo(p_adapters, (PULONG)all_adapter_size);
		}
		while (p_adapters){
			std::cout << "网卡名称"<< p_adapters->AdapterName<<std::endl;
			std::cout << "网卡描述" << p_adapters->Description << std::endl;
			std::cout << "IP地址" << p_adapters->IpAddressList.IpAddress.String << std::endl;
			std::cout << "子网掩码" << p_adapters->IpAddressList.IpMask.String << std::endl;
			p_adapters = p_adapters->Next;
		}
		delete p_adapters;
		return true;
	}

#else
	bool GetAllAdapter(std::vector<Adapter>*list)
	{
		return true;
	}
#endif
};