#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

int size=100;
int array[1000];
void *TestThread(void *arg)
{
	int start=(int)arg;
	int end=start+size;
	int sum=0;
	for(int i=start;i<end;i++)
	{
		sum=sum+array[i];
		//return((void*)sum);
	}
}
int main()
{
	int status[10];
	pthread_t threads[10];
	for(int i=0;i<1000;i++)
	{
		array[i]=i;
	}
	for(int i=0;i<10;i++)
	{
		pthread_create(&threads[i],NULL,TestThread,(void*)(i*size));
		
	}
	for(int i=0;i<10;i++)
	{
		pthread_join(threads[i],(void**)&status[i]);
	}
	int sum1=0;
	for(int i=0;i<10;i++)
	{
		sum1=sum1+status[i];
	}
	printf("The sum is: %d",sum1);
	return 0;

}
