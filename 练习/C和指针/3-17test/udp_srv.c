//udp服务端程序的流程，学习使用各个套接字接口以及梳理udp通信的实现流程
//1.创建套接字
//2.为套接字绑定地址信息
//3.接收数据
//4.发送数据
//5.关闭套接字
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
	//通过参数灵活获取IP地址和端口信息
	if(argc!=3){
		printf("./udp_srv ip port\n");
		return -1;
	}
	char *addr_ip=argv[1];
	uint16_t addr_port = atoi(argv[2]);
	//创建套接字
	int sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(sockfd<0){
		perror("socket error");
		return -1;
	}
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	//htons将一个短整型（uint16_t）类型的数据转换为网络字节序
	//inet_addr将点分十进制IP地址转换为网络字节序的整数IP地址
	addr.sin_port = htons(addr_port);
	addr.sin_addr.s_addr = inet_addr(addr_ip);
	socklen_t len = sizeof(struct sockaddr_in);
	int ret = bind(sockfd,(struct sockaddr*)&addr,len);
	if(ret<0){
		perror("bind error");
		return -1;
	}
		
	return 0;
}
