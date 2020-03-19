#pragma once
#include"udp_socket.hpp"
#include <functional>
//typedef std::function<void (const std::string&, std::string* resp)> Handler;
typedef void (*Handler)(const std::string& req, std::string* resp);
class UdpServer{
private:
	UdpSocket sock_;
public:
	UdpServer(){
		assert(sock_.Socket());
	}
	~UdpServer(){
		sock_.Close();
	}

	bool start(const std::string& ip,uint16_t port,Handler handler){
		//1.创建Socket
		//2.绑定端口号
		bool ret = sock_.Bind(ip,port);
		if(ret!=true){
			perror("bind error\n");
			return false;
		}
		//3.进入事件循环
		for(;;){
			//4.尝试读取请求
			std::string req;
			std::string remote_ip;
			uint16_t remote_port = 0;
			bool ret = sock_.Recvfrom(&req,&remote_ip,&remote_port);
			if(ret!=true)continue;
			std::string resp;
			// 5. 根据请求计算响应
			handler(req, &resp);
			// 6. 返回响应给客户端
			sock_.SendTo(resp, remote_ip, remote_port);
			printf("[%s:%d] req: %s, resp: %s\n", remote_ip.c_str(), remote_port,
			req.c_str(), resp.c_str());
		}
		sock_.Close();
		return true;
	}
};
