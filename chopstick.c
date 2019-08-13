#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>


#define thinking 1
#define hungry 1
#define eating 1
#define MAX 20

sem_t chop[5];    //5 chopstick semaphores.
int state[5];    //state of mutexes ie wether hungry or not, eating or not, thinking or not.
sem_t mutex;
int philosophers[5] = {0,1,2,3,4};  //init philosophers as 0,1,2,3,4

void take_chopstick(int philno)
{
	sem_wait(&mutex);
	state[philno]=HUNGRY;
	printf("\n\nPhilosopher %d is hungry\n");
	check();
	sem_post(&mutex);
	sem_wait(&P[philno]);
	sleep(1);
}




void init(){

    int i;
    
    for(i=0;i<5;i++)
    {
        sem_init(&chop[i],0,1)   //init all the chopsticks
    }
    
    sem_init(&mutex,0,1);       //init the mutex

}

int main()
{

    pthread_t *philosophers[5];
    init();
    
    printf("create threads for philosophers.");
    
    for(int j = 0;j<5;j++)
    {
       int* arg = (int*)malloc(sizeof(int));
       *arg = j;
       pthread_create(&phil[5],NULL,diner_phil,(void*)arg);  //thread creation for semaphores
          
    }
    for(int k=0;k<5;k++)
    {
        pthread_join(&philosopher,NULL);              ///thread joining for semaphores
    }

}


void* diner_phil(void* arg)
{
	int i=*(int* )arg;
	printf("\n\nPhilosopher %d wants to eat",i);
	while(1)
	{
		if((i)%2==0)
		{
			sem_wait(&chop[i]);
			sem_wait(&chop[(i+1)%5]);
		}
		else
		{
			sem_wait(&chop[(i+1)%5]);
			sem_wait(&chop[i]);
		}
		printf("\n\nPhilosopher %d is eating",i);
		
		sleep(rand()%7);
		
		printf("\n\nPhilosopher %d is thinking",i);
		if((i)%2==0)
		{
			sem_post(&chop[i]);
			sem_post(&chop[(i+1)%5]);
		}
		else
		{
			sem_post(&chop[(i+1)%5]);
			sem_post(&chop[i]);
		}
	}
}
