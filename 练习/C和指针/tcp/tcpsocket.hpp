//封09装tcpsocket对象，通过实例化的tcpsocket对象，来实现数据的通信
#ifndef __M_TCP_H__
#define __M_TCP_H__
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cassert>
#include<unistd.h>
#define CHECK_RET(q) if((q)==false){return -1;}
#define MAX_LISTEN 100
class TcpSocket{
private:
	int _sockfd;
private:
	void MakeAddr(struct sockaddr_in &addr,
			const std::string &ip,const uint16_t port){
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
	}
public:
	TcpSocket():_sockfd(-1){}
	//1.创建套接字
	bool Socket(){
		_sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(_sockfd<0){
			perror("socket error\n");
			return false;
		}
		return true;
	}
	//2.绑定地址信息
	bool Bind(const std::string &ip,uint16_t port){
		struct sockaddr_in addr;
		MakeAddr(addr,ip,port);
		socklen_t len =sizeof(struct sockaddr_in);
		int ret = bind(_sockfd,(struct sockaddr*)&addr,len);
		if(ret<0){
			perror("bind error\n");
			return false;
		}		
		return true;
	}
	//3.开始监听
	bool Listen(int backlog = MAX_LISTEN){
		int ret = listen(_sockfd,backlog);
		if(ret<0){
			perror("listen error\n");
			return false;
		}
		return true;
	}
	//3.发起请求连接
	bool Connect(const std::string &ip,const uint16_t port){
			struct sockaddr_in addr;
			MakeAddr(addr,ip,port);
			socklen_t len = sizeof(struct sockaddr_in);
				
			int ret = connect(_sockfd,(struct sockaddr*)&addr,len);
			if(ret<0){
				perror("connect false\n");
				return false;
			}
			return true;
	}
	//4.获取新连接
	bool Accept(TcpSocket *sock,std::string *ip = NULL,uint16_t *port = NULL){
		//int accept(int sockfd,struct sockaddr* cliaddr,socklen_t len);
		struct sockaddr_in addr;
		socklen_t len = sizeof(struct sockaddr_in);
		//获取新连接套接字字符
		int newfd = accept(_sockfd,(struct sockaddr*)&addr,&len);
		if(newfd<0){
			perror("accept error\n");
			return false;
		}
		sock->_sockfd = newfd;
		if(ip!=NULL){
			//inet_ntoa 将网络字节序转换为字符串
			*ip = inet_ntoa(addr.sin_addr);
		}
		if(port!=NULL){
			*port = ntohs(addr.sin_port);
		}
		return true;
	}
	//5.接收数据
	bool Recv(std::string &buf){
		char tmp[1024*10] = {0};
		int rlen = recv(_sockfd,tmp,sizeof(tmp),0);
		if(rlen<0){
			perror("recv error\n");
			return false;
		}else if(rlen == 0){
			perror("peer shutdown\n");
			return false;
		}
		buf.assign(tmp,rlen);
		return true;
	}
	//6.发送数据
	bool Send(std::string &buf){
		//int send(int fd,char*buf,int len,int flsg)
		int ret = send(_sockfd,buf.data(),buf.size(),0);
		if(ret<0){
			perror("send error\n");
			return false;
		}
		return true;
	}
	//7.关闭套接字
	bool Close(){
		close(_sockfd);
		return true;
	}
};
#endif
