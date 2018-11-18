#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in serv_addr;
	char m[1000],reply[2000];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{	
		printf("Error openning socket");
	}
	puts("socket created");
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(8888);
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		perror("Error connecting");
		return 1;
	}
	puts("Connection");
	while(1)
	{
		printf("Hello World");
		//scanf("%s",m);
		if(send(sockfd,m,strlen(m),0)<0)
		{
			puts("Error reading from socket");
			return 1;		
		}
		if(recv(sockfd,reply,2000,0)<0)
		{
			puts("recieved failed");
			break;
		}
		puts("Server reply:");
		puts(reply);
	}
close(sockfd);
return 0;
}

