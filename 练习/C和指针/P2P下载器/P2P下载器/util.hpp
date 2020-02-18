#pragma once 

#ifdef _WIN32
//Windowsͷ�ļ�
#include<iostream>
#include<vector>
#include<stdint.h>
#include<fstream>
#include<boost/filesystem.hpp>
#include<WS2tcpip.h>
#include<IPHlpApi.h>//��ȡ������Ϣ�ӿڵ�ͷ�ļ�
#pragma comment(lib,"Iphlpapi.lib")//��ȡ������Ϣ�Ŀ�
#pragma comment(lib,"ws2_32.lib")
#else
//Linuxͷ�ļ�
#endif

class FileUtil{
public:
	static bool Write(const std::string &name, const std::string &body, int64_t offset=0){

		std::ofstream ofs(name);
		if (ofs.is_open() == false){
			std::cerr << "���ļ�ʧ��";
			return false;
		}
		ofs.seekp(offset, std::ios::beg);//��дλ����ת��������ļ���ʼλ�ÿ�ʼƫ��offset��ƫ����
		ofs.write(&body[0], body.size());
		if (ofs.good() == false){
				std::cerr << "���ļ�д������ʧ��\n";
				ofs.close();
				return false;
		}
		ofs.close();
		return true;
	}
	//ָ�������ʾ����һ������Ͳ���
	//const &��ʾ����һ�������Ͳ���
	//& ��ʾ����һ����������Ͳ���
	static bool Read(const std::string &name, std::string *body){
		std::ifstream ifs(name);
		if (ifs.is_open() == false){
			std::cerr << "���ļ�ʧ��";
			return false;
		}
		int64_t filesize = boost::filesystem::file_size(name);
		body->resize(filesize);
		ifs.read(&(*body)[0], filesize);
		/*if (ifs.good() == false)
		{
			std::cerr << "��ȡ�ļ�ʧ��";
			ifs.close();
			return false;
		}*/
		ifs.close();
		return true;
	}
};

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
		PIP_ADAPTER_INFO p_adapters = new IP_ADAPTER_INFO();//����һ��������Ϣ�ṹ�Ŀռ�
		//��ȡ������Ϣ���ܻ�ʧ�ܣ���Ϊ�ռ䲻�㣬�����һ������Ͳ���
		uint64_t all_adapter_size = sizeof(p_adapters);
		int ret = GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		if (ret == ERROR_BUFFER_OVERFLOW){//�������ڴ治��
			delete p_adapters;
			p_adapters = (PIP_ADAPTER_INFO)new BYTE[all_adapter_size];
			GetAdaptersInfo(p_adapters, (PULONG)&all_adapter_size);
		}
		while (p_adapters)
		{
			Adapter adapter;
			inet_pton(AF_INET, p_adapters->IpAddressList.IpAddress.String,&adapter._ip_addr);//��һ���ַ������ʮ���Ƶ�IP��ַת��Ϊ�����ֽ����IP��ַ
			inet_pton(AF_INET, p_adapters->IpAddressList.IpMask.String, &adapter._ip_addr);
			adapter._ip_addr = inet_addr(p_adapters->IpAddressList.IpAddress.String);
			adapter._mask_addr = inet_addr(p_adapters->IpAddressList.IpMask.String);
			if (adapter._ip_addr != 0)//��Ϊ��Щ������û������
			{
				list->push_back(adapter);//��������Ϣ��ӵ�vector
				/*std::cout << "��������" << p_adapters->AdapterName << std::endl;
				std::cout << "��������" << p_adapters->Description << std::endl;
				std::cout << "����IP��ַ" << p_adapters->IpAddressList.IpAddress.String << std::endl;
				std::cout << "��������" << p_adapters->IpAddressList.IpMask.String << std::endl;
				std::cout << std::endl;*/
			}
			p_adapters = p_adapters->Next;

		}
		delete p_adapters;
		return true;
	}
#else//Linux�µĻ�ȡ������Ϣ
	bool GetAllAdapter(std::vector<Adapter> *list){
		return true;
	}
#endif
};