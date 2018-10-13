#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
	
	int arr[1000];
	int size=1000;
	int i=0;
	for(i=0;i<size;i++)
	{
	   arr[i]=i+1;
	}
	   int fd[10][2];
	for(int i=0;i<10;i++)
	{
	   pipe(fd[i]);
	}
	int cpid=fork();
	if(cpid==0)
	{
	    int sum=0;
		for(int i=0;i<100;i++)
		{
		   sum=sum+arr[i];
		}
		write(fd[0][1],&sum,sizeof(sum));
		close(fd[0][1]);
	}
	else
	{
	   	int cpid2=fork();
		if(cpid2==0)
		{
		   int sum2=0; 
		   for(int i=100;i<200;i++)
		{
		
		   sum2=sum2+arr[i];
		}
		write(fd[1][1],&sum2,sizeof(sum2));
		close(fd[1][1]);
		
	   	}
	else
	{	
		int cpid3=fork();
	   	if(cpid==0)
	   {	
		int sum3=0;
		for(int i=200;i<300;i++)
		{
		   sum3=sum3+arr[i];
		}
		write(fd[2][1],&sum3,sizeof(sum3));
		close(fd[2][1]);
	   }
	else
	{
		int cpid4=fork();
	   	if(cpid4==0)
	   {
		int sum4=0;
		for(int i=300;i<400 ;i++)
		{
		   sum4=sum4+arr[i];
		}
		write(fd[3][1],&sum4,sizeof(sum4));
		close(fd[3][1]);
	   }
	else
	{
		int cpid5=fork();
	   	if(cpid5==0)
	   {
		int sum5=0;
		for(int i=400;i<500;i++)
		{
		   sum5=sum5+arr[i];
		}
		write(fd[4][1],&sum5,sizeof(sum5));
		close(fd[4][1]);
	   }
	else
	{
		int cpid6=fork();
	   	if(cpid6==0)
	   {
		int sum6=0;
		for(int i=500;i<600;i++)
		{
		   sum6=sum6+arr[i];
		}
		write(fd[5][1],&sum6,sizeof(sum6));
		close(fd[5][1]);
	   }
	else
	{
		int cpid7=fork();
	   	if(cpid7==0)
	   {
		int sum7=0;
		for(int i=600;i<700;i++)
		{
		   sum7=sum7+arr[i];
		}
		write(fd[6][1],&sum7,sizeof(sum7));
		close(fd[6][1]);
	   }
	else
	{
		int cpid8=fork();
	   	if(cpid8==0)
	   {
		int sum8=0;
		for(int i=700;i<800;i++)
		{
		   sum8=sum8+arr[i];
		}
		write(fd[7][1],&sum8,sizeof(sum8));
		close(fd[7][1]);
	   }
	else
	{
		int cpid9=fork();
	   	if(cpid9==0)
	   {
		int sum9=0;
		for(int i=800;i<900;i++)
		{
		   sum9=sum9+arr[i];
		}
		write(fd[8][1],&sum9,sizeof(sum9));
		close(fd[8][1]);
	   }
	else
	{
		int cpid10=fork();
	   	if(cpid10==0)
	   {
		int sum10=0;
		for(int i=900;i<1000;i++)
		{
		   sum10=sum10+arr[i];
		}
		write(fd[9][1],&sum10,sizeof(sum10));
		close(fd[9][1]);
	   }
	else
	{
		for(int j=0;j<10;j++)
		wait(NULL);
	 }
	}
       }
      }
     }
    }
   }
  }
 }
}
int Sum1,Sum2,Sum3,Sum4,Sum5,Sum6,Sum7,Sum8,Sum9,Sum10;
		read(fd[0][0],&Sum1,sizeof(Sum1));
		close(fd[0][0]);
		read(fd[1][0],&Sum2,sizeof(Sum2));
		close(fd[1][1]);
		read(fd[2][0],&Sum3,sizeof(Sum3));
		close(fd[2][1]);
		read(fd[3][0],&Sum4,sizeof(Sum4));
		close(fd[3][1]);
		read(fd[4][0],&Sum5,sizeof(Sum5));
		close(fd[4][1]);
		read(fd[5][0],&Sum6,sizeof(Sum6));
		close(fd[5][1]);
		read(fd[6][0],&Sum7,sizeof(Sum7));
		close(fd[6][1]);
		read(fd[7][0],&Sum8,sizeof(Sum8));
		close(fd[7][1]);
		read(fd[8][0],&Sum9,sizeof(Sum9));
		close(fd[8][1]);
		read(fd[9][0],&Sum10,sizeof(Sum10));
		close(fd[9][1]);
int Sum=Sum1+Sum2+Sum3+Sum4+Sum5+Sum6+Sum7+Sum8+Sum9+Sum10;
printf("%d\n",Sum);
}





