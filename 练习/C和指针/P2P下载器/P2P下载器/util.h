#pragma once//ͷ�ļ�������һ��
#ifdef _WIN32
//winͷ�ļ�
#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<IPHlpApi.h>
#include<vector>
#include<stdint.h>
#pragma comment(lib, "Iphlpapi.lib")

#else
//Linuxͷ�ļ�

#endif
class Adapter{
public:
	uint32_t _ip_addr;//�����ϵ�IP��ַ
	uint32_t _mask_addr;//�����ϵ���������
};

class AdapterUtil{
#ifdef _WIN32
	//windows�µĻ�ȡ������Ϣʵ��
public:
	static bool GetAllAdapter(std::vector<Adapter>*list){
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();
			//GetAdaptersInfo win�»�ȡ��������Ϣ�Ľ��--������Ϣ�п����ж������˴���һ��ָ��
		//��ȡ������Ϣ���ܻ�ʧ�ܣ���˿ռ䲻�㣬�����һ������Ͳ������������û����ص����ж�������
		uint64_t all_adapter_size = sizeof(IP_ADAPTER_INFO);
		int ret = GetAdaptersInfo(p_adapters,(PULONG)all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW)//��ǰ������������������ռ䲻�㣬������¸�ָ������ռ�
		{
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			GetAdaptersInfo(p_adapters, (PULONG)all_adapter_size);
		}
		while (p_adapters){
			std::cout << "��������"<< p_adapters->AdapterName<<std::endl;
			std::cout << "��������" << p_adapters->Description << std::endl;
			std::cout << "IP��ַ" << p_adapters->IpAddressList.IpAddress.String << std::endl;
			std::cout << "��������" << p_adapters->IpAddressList.IpMask.String << std::endl;
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