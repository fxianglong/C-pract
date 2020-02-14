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
	bool _pair_ret;//���ڴ����Խ��
};
class Client{
public:
	//������Ե��߳���ں���
	void HostPair(Host *host)
	{
		//1.��֯httpЭ���ʽ����������
		//2.�һ��tcp�Ŀͻ��˶��󣬽����ݷ���
		//3.�ȴ��������˵Ļظ��������н���
		//4.
		host->_pair_ret = false;
		char buf[MAX_IPBUFFER] = { 0 };
		inet_ntop(AF_INET, &host->_ip_addr, buf, MAX_IPBUFFER);//�������ֽ���ת��Ϊ
		httplib::Client cli(buf, P2P_PORT);//ʵ����httplib�ͻ��˶���
		auto rsp = cli.Get("/hostpair");//�����˷�����ԴΪ/hostpair��Get����//������ӽ���ʧ��Get�᷵��NULL
		if (rsp && rsp->status == 200){//�ж���Ӧ����Ƿ���ȷ
			host->_pair_ret = true;//��������ƥ��ṹ
		}
	}
	bool GetOnlineHost()//��ȡ��������
	{
		//1.��ȡ������Ϣ�������õ������������е�IP��ַ�б�
		std::vector<Adapter> list;
		AdapterUtil::GetAllAdapter(&list);
		//��ȡ�����������
		std::vector<Host> host_list;
		for (int i = 0; i < list.size(); i++)
		{
			uint32_t ip = list[i]._ip_addr;
			uint32_t mask = list[i]._mask_addr;
			//���������
			uint32_t net = (ip & mask);
			//��������������
			uint32_t max_host = (~ntohl(mask));//�������IP�ļ���Ӧ��ʹ��С��������
			
			std::vector<bool> ret_list(max_host);
			for (int j = 1; j < max_host; j++)//�õ����е�����IP��ַ�б�
			{
				uint32_t host_ip = net + j;
				Host host;
				host._ip_addr = htonl(host_ip);//�������ֽ���ת��Ϊ�ַ����ֽ���
				host._pair_ret = false;
				host_list.push_back(host);
			}
				//2.�����IP��ַ�б��е����������������
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
		//3.���������õ���Ӧ�����Ӧ����λ������������IP��ӵ�_online_host�б���
		//4.��ӡ���������б�ʹ�û�ѡ��
		std::cout << "���û������������ȡ�����ļ��б�";
		fflush(stdout);
		std::string select_ip;
		std::cin >> select_ip;
		GetShareList(select_ip);

	}
	bool GetShareList(const std::string &host_ip)//��ȡ�ļ��б�
	{
		//�����������һ���ļ��б��ȡ����
		//1.�ȷ�������
		//2.�õ���Ӧ֮���������
		httplib::Client cli(host_ip ,P2P_PORT);
		auto rsp = cli.Get("/liat");
		if (rsp == NULL || rsp->status != 200)
		{
			std::cerr << "��ȡ�ļ��б����";
			return false;
		}
		std::cout << rsp->body<<std::endl;
		std::cout << "ѡ��Ҫ���ص��ļ�";
		fflush(stdout);
		std::string filename;
		std::cin >> filename;
		DownloadFile(host_ip,filename);
		return true;
	}
	bool DownloadFile(const std::string &host_ip,const std::string &filename)//�����ļ�
	{
		//1.�����˷����ļ���������
		//2.�õ���Ӧ�������Ӧ����е�Body���ľ����ļ�����

		std::string req_path = "/download/" + filename;
		httplib::Client cli(host_ip, P2P_PORT);
		auto rsp = cli.Get(req_path);
		if (rsp == NULL || rsp.status != 200){
			std::cerr << "�����ļ�����ȡ��Ӧ��Ϣʧ��\n";
			return false;
		}
		if (FileUtil::Write(filename, rsp->body) == false){
			std::cerr << "�ļ�����ʧ��\n";
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
		  //�����Կͻ�������Ĵ���ʽ��Ӧ��ϵ
		_srv.Get("/hostpair", HostPair);
		_srv.Get("/list", ShareList);
		_srv.Get("/download/.*",Download);//������ʽ.��ʾ��/n/r֮��������ַ���*����ʾƥ��ǰ���ַ������
		_srv.listen("0.0.0.0", P2P_PORT);
		return true;
}
private:
	static bool HostPair(const httplib::Request &req,httplib::Response &rsp){
		rsp.status = 200;
		return;
	}
	//��ȡ�����ļ��б�--������������һ������Ŀ¼
	static bool ShareList(const httplib::Request &req, httplib::Response &rsp){
		boost::filesystem::directory_iterator begin(SHARED_PATH);//ʵ����Ŀ¼������
		boost::filesystem::directory_iterator end;
		//��ʼ����Ŀ¼
		for (; begin != end; ++begin){
			if (boost::filesystem::is_directory(begin->status())){
				//��ǰ�汾����ֻ��ȡ��ͨ�ļ����ƣ�������㼶Ŀ¼�Ĳ���
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
		std::string realpath = SHARED_PATH + '/' + name;//ʵ���ļ���·��Ӧ�����ڹ����ļ���Ŀ¼��
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