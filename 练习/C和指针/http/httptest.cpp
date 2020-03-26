#include<iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc,char *argv[]){
	if(argc!=3)
	{
		printf("./httptest: ip port\n");
		return -1;
	}
	int fd=socket(AF_INET,SOCK_STREAM,0);
		if(fd<0){
			printf("sock perror\n");
			return -1;
		}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	addr.sin_port = htons(atoi(argv[2]));
	int ret = bind(fd,(struct sockaddr*)&addr,sizeof(addr));
	if(ret<0){
		printf("bind error\n");
		return -1;
	}
	ret = listen(fd,10);
		if(ret<0){
			printf("listen error\n");
			return -1;
		}

	for(;;){
		struct sockaddr_in cli_sock;
		socklen_t len;
		int cli_fd = accept(fd,(struct sockaddr*)&cli_sock,&len);
		if(cli_fd<0){
			printf("accept error\n");
			continue;
		}

		char tmp[1024*10]={0};
		int read_size = read(cli_fd,&tmp,sizeof(tmp)-1);
		if(read_size<0){
			printf("read error\n");
			return 1;
		}

		 printf("[Request] %s", tmp);
		 char buf[1024]={0};
		 const char* hello = "<html><body><h1>hello world</h1></body></html>";
		 sprintf(buf, "HTTP/1.0 200 OK\nContent-Length:%lu\n\n%s", strlen(hello), hello);
		 write(cli_fd, buf, strlen(buf));
	}
	return 0;

}
