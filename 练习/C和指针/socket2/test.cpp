#include<stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(){
	struct sockaddr_in addr;
	inet_aton("127.0.0.0",&addr.sin_addr);
	uint32_t *ptr = (uint32_t*)(&addr.sin_addr);
	printf("%x\n",*ptr);
	printf("%s\n",inet_ntoa(addr.sin_addr));
	return 0;
}
