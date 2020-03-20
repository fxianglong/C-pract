#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cassert>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
class UdpSocket{
private:
	int fd_;
public:
	UdpSocket():fd_(-1){}
	bool Socket(){
		int ret = socket(AF_INET,SOCK_DGRAM,0);
		if(ret<0){
			perror("socket error\n");
			return false;
		}
		return true;
	}

	bool Close(){
		close(fd_);
		return true;
	}

	bool Bind(const std::string &ip,uint16_t port){
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		addr.sin_port = port;
		int ret = bind(fd_,(sockaddr*)&addr,sizeof(addr));
		if(ret<0){
			perror("bind error\n");
			return false;
		}
		return true;
	}

	bool RecvFrom(std::string *buf,std::string *ip = NULL,uint16_t *port = NULL){
		char tmp[1024*10] = {0};
		sockaddr_in peer;
		socklen_t len = sizeof(peer);
		int read_size = recvfrom(fd_,tmp,sizeof(tmp)-1,0,(sockaddr*)&peer,&len);
		if(read_size<0){
			perror("recvfrom error\n");
			return false;
		}
		buf->assign(tmp,read_size);
		if(ip!=NULL){
			*ip = inet_ntoa(peer.sin_addr);
		}
		if(port!=NULL){
			*port = ntohs(peer.sin_port);
		}
		return true;
	}

	bool SendTo(std::string &buf,std::string &ip,uint16_t port){
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = SOCK_DGRAM;
		addr.sin_port = htons(port);
		int write_size = sendto(fd_,buf.data(),buf.size(),0,(sockaddr*)&addr,sizeof(addr));
		if(write<0){
			perror("sendto error\n");
			return false;
		}
		return true;
	}
};
