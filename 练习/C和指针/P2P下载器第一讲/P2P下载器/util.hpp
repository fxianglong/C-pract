#pragma once 

#ifdef _WIN32
//Windowsͷ�ļ�
#include<iostream>
#include<vector>
#include<stdint.h>
#include<WS2tcpip.h>
#include<IPHlpApi.h>
#pragma comment(lib,"Iphlpapi.lib")
#else
//Linuxͷ�ļ�
#endif

class Adapter{
public:
	uint32_t _ip_addr;//�����ϵ�IP��ַ
	uint32_t _mask_addr;//�����ϵ���������
};

class AdapterUtil
{
#ifdef _WIN32//windows�µĻ�ȡ������Ϣ�Ľ��
public:
	static bool GetAllAdapter(std::vector<Adapter> *list){
		//PIP_ADAPTER_INFO���������Ϣ
		PIP_ADAPTER_INFO p_adapter = new IP_ADAPTER_INFO();
		//��ȡ������Ϣ���ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬�����һ������Ͳ���
		uint64_t info_size = sizeof(p_adapter);
		int ret = GetAdaptersInfo(p_adapter, (PULONG)&info_size);
		if (ret == ERROR_BUFFER_OVERFLOW){//�������ڴ治��
			delete p_adapter;
			p_adapter = (PIP_ADAPTER_INFO)new BYTE[info_size];
			GetAdaptersInfo(p_adapter, (PULONG)&info_size);
		}
		while (p_adapter)
		{
			std::cout << "��������" << p_adapter->AdapterName<<std::endl;
			std::cout << "��������" << p_adapter->Description<<std::endl;
			std::cout << "����IP��ַ" << p_adapter->IpAddressList.IpAddress.String << std::endl;
			std::cout << "��������" << p_adapter->IpAddressList.IpMask.String << std::endl;

			p_adapter = p_adapter->Next;

		}
		delete p_adapter;
		return true;
	}
#else//Linux�µĻ�ȡ������Ϣ
	bool GetAllAdapter(std::vector<Adapter> *list){
		return true;
	}
#endif
};