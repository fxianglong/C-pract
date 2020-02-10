#pragma once 

#ifdef _WIN32
//Windows头文件
#include<iostream>
#include<vector>
#include<stdint.h>
#include<WS2tcpip.h>
#include<IPHlpApi.h>
#pragma comment(lib,"Iphlpapi.lib")
#else
//Linux头文件
#endif

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
		PIP_ADAPTER_INFO p_adapter = new IP_ADAPTER_INFO();
		//获取网卡信息可能会失败，因为空间不足，因此有一个输出型参数
		uint64_t info_size = sizeof(p_adapter);
		int ret = GetAdaptersInfo(p_adapter, (PULONG)&info_size);
		if (ret == ERROR_BUFFER_OVERFLOW){//缓冲区内存不足
			delete p_adapter;
			p_adapter = (PIP_ADAPTER_INFO)new BYTE[info_size];
			GetAdaptersInfo(p_adapter, (PULONG)&info_size);
		}
		while (p_adapter)
		{
			std::cout << "网卡名称" << p_adapter->AdapterName<<std::endl;
			std::cout << "网卡描述" << p_adapter->Description<<std::endl;
			std::cout << "网卡IP地址" << p_adapter->IpAddressList.IpAddress.String << std::endl;
			std::cout << "子网掩码" << p_adapter->IpAddressList.IpMask.String << std::endl;

			p_adapter = p_adapter->Next;

		}
		delete p_adapter;
		return true;
	}
#else//Linux下的获取网卡信息
	bool GetAllAdapter(std::vector<Adapter> *list){
		return true;
	}
#endif
};