#pragma once
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<unistd.h>
#include<cassert>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
typedef struct sockaddr aockaddr;
typedef struct sockaddr_in sockaddr_in;

#define CHECK_RET(exp) if (!(exp)) {\
	return false;\
}
class TcpSocket{
private:
	int fd_;
public:
	TcpSocket():fd_(-1){}
	TcpSocket(int fd):fd_(fd){}

	bool Socket(){
		fd_ = socket(AF_INET,SOCK_DGRAM,0);
		if(fd_<0){
			perror("socket error\n");
			return false;
		}
		printf("open fd:%d\n",fd_);
		return true;
	}

	bool Close()const{
		close(fd_);
		printf("close fd:%d\n",fd_);
		return true;
	}

	bool Bind(const std::string &ip,uint16_t port)const{
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

	bool Listen(int num)const{
		int ret = listen(fd_,num);
		if(ret<0){
			perror("listen error\n");
			return false;
		}
		return true;
	}

	bool Accept(TcpSocket* peer,std::string *ip=NULL,uint16_t* port=NULL)const{
		sockaddr_in peer_addr;
		socklen_t len = sizeof(peer_addr);
		int new_sock = accept(fd_,(sockaddr*)&peer_addr,&len);
		if(new_sock<0){
			perror("accept error\n");
			return false;
		}
		printf("accept fd:%d\n",fd_);
		peer->fd_ = new_sock;
		if(ip!=NULL)
			*ip = inet_ntoa(peer_addr.sin_addr);
		if(port!=NULL)
			*port = ntohs(peer_addr.sin_port);
		return true;
	}

	bool Recv(std::string *buf){
		buf->clear();
		char tmp[1024*10] = {0};
		ssize_t read_size = recv(fd_,tmp,sizeof(tmp),0);
		if(read_size<0){
			perror("recv error\n");
			return false;
		}
		if(read_size==0){
			return false;
		}
		buf->assign(tmp,read_size);
		return true;
	}

	bool Send(const std::string &buf)const{
		ssize_t write_size = send(fd_,buf.data(),buf.size(),0);
		if(write_size<0){
			perror("send error\n");
			return false;
		}
		return true;
	}

	bool Connect(std::string &ip,uint16_t port){
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		addr.sin_port = htons(port);
		int ret = connect(fd_,(sockaddr*)&addr,sizeof(addr));
		if(ret<0){
			perror("connect error\n");
			return false;
		}
		return true;
	}

	int GetFd()const{
		return fd_;
	}
};
