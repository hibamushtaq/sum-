#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc,char *argv[])
{
	int sockfd,newsockfd,portno,clilen,size;
	struct sockaddr_in serv_addr,client;
	char m[2000];
	int n;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{	
		perror("Error opening socket");
	}
	puts("Socket created");
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(8888);
	
	if(bind(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
	{
		perror("Error on binding");
		return 1;
	}
	puts("Bind done");
	listen(sockfd,3);
	puts("Waiting for incoming connections......");
	clilen=sizeof(struct sockaddr_in);
	newsockfd=accept(sockfd,(struct sockaddr *) &client,(socklen_t*)&clilen);
	if(newsockfd<0)
	{
		perror("Error on accept");
		return 1;
	}
	puts("Connection accepted");
	while((size=recv(newsockfd,m,2000,0))>0)
	{
		write(newsockfd,m,strlen(m));
	}	
	if(size==0)
	{
		puts("Client Disconnected");
		fflush(stdout);
		
	}
	else
	if(size==-1)
	{
		perror("recieved failed");
	}
return 0;
}
