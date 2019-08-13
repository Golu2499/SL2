//Name     : Neha Jaju
//Batch    : L 10
//Roll no. : 33224
#include<stdio.h> 
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define max 20

sem_t chopstick[5];

void* dining_philo(void* arg)
{
	int i=*(int* )arg;
	printf("\n\nPhilosopher %d wants to eat",i);
	while(1)
	{
		if((i)%2==0)
		{
			sem_wait(&chopstick[i]);
			sem_wait(&chopstick[(i+1)%5]);
		}
		else
		{
			sem_wait(&chopstick[(i+1)%5]);
			sem_wait(&chopstick[i]);
		}
		printf("\n\nPhilosopher %d is eating",i);
		
		sleep(rand()%7);
		
		printf("\n\nPhilosopher %d is thinking",i);
		if((i)%2==0)
		{
			sem_post(&chopstick[i]);
			sem_post(&chopstick[(i+1)%5]);
		}
		else
		{
			sem_post(&chopstick[(i+1)%5]);
			sem_post(&chopstick[i]);
		}
	}
}
void init()
{
	int i;
	for(i=0;i<5;i++)
	{
		sem_init(&chopstick[i],0,1);
	}
}
int main()
{
	int i;
	pthread_t phil[5];
	init();
	printf("Creating thread for philosophers\n");

	for(i=0;i<5;i++)
	{
		int* arg=(int*)malloc(sizeof(int));
		*arg=i;
		pthread_create(&phil[i],NULL,*dining_philo,(void *)arg);
	}
	for(i=0;i<5;i++)
	{
		pthread_join(phil[i],NULL);
	}
}
