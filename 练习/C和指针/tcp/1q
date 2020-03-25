#include"tcpsocket.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thr_start(void *arg){
	while(1){
	TcpSocket *cli_sock = (TcpSocket*)arg;
	std::string buf;
	bool ret = cli_sock->Recv(buf);
	if(ret==false){
		cli_sock->Close();
		break;
	}
	std::cout<<"client say:"<<buf<<"\n";
	std::cout<<"server say:";
	fflush(stdout);
	buf.clear();
	std::cin>>buf;
	bool rst = cli_sock->Send(buf);
	if(rst==false){
		cli_sock->Close();
		break;
	}
	cli_sock->Close();
	delete cli_sock;
	return NULL;
}}
int main(int argc,char* argv[]){
	if(argc!=3){
		std::cout<<"./tcp_srv ip port\n";
		return -1;
	}
	std::string ip = argv[1];
	uint16_t port = atoi(argv[2]);
	TcpSocket lst_sock;
	CHECK_RET(lst_sock.Socket());
	CHECK_RET(lst_sock.Bind(ip,port));
	CHECK_RET(lst_sock.Listen());
	//TcpSocket cli_sock;
	while(1){
		TcpSocket *cli_sock = new TcpSocket();
		std::string cli_ip;
		uint16_t cli_port;
		if(lst_sock.Accept(cli_sock,&cli_ip,&cli_port)==false){
			continue;
		}
		pthread_t tid;
		pthread_create(&tid,NULL,thr_start,(void*)cli_sock);
		pthread_detach(tid);
		//cli_sock用于于指定的客户端进行通信
		//list_sock只用于获取新连接
		
	}
	lst_sock.Close();
	return 0;
}
