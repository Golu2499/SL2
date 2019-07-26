#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

#define B_SIZE 100
#define max 20
typedef struct
{
   int in,out;
   int buffer[B_SIZE];
   sem_t empty;
   sem_t full;
   pthread_mutex_t bufflock;

}BUFFER;
BUFFER b;
int item=1;
void init();
void *producer(void *arg);
void *consumer(void *arg);


int main(void)
{
      int i,np,nc;
      pthread_t pid[max],cid[max];
     
      init();
      printf("Enter the number of producers : ");
      scanf("%d",&np);
      
      printf("Enter the number of consumers : ");
      scanf("%d",&nc);

      for(i=0;i<np;i++)
      {   
           void *arg=&i;
           pthread_create(&pid[i],NULL,*producer,(void *)arg);
      }
      
      for(i=0;i<nc;i++)
      {   
           void *arg=&i;
           pthread_create(&cid[i],NULL,*consumer,(void *)arg);
      }
      
      for(i=0;i<np;i++)
      {
          pthread_join(pid[i],NULL);
      }
      
      for(i=0;i<nc;i++)
      {   
          pthread_join(cid[i],NULL);
      }
      
      return 0;
}
void init()
{
    b.in=0;
    b.out=0;
    sem_init(&b.empty,0,B_SIZE);
    sem_init(&b.full,0,0);
    pthread_mutex_init(&b.bufflock,NULL);
}
void *producer(void *arg)
{  int i=*(int *)arg;
   int k;
    while(1)
    {  
    
    sem_wait(&b.empty);
    printf("Producer %d produced item %d\n",i+1,item++);
    sleep(1);
    pthread_mutex_lock(&b.bufflock);
    b.buffer[(b.in++)%B_SIZE]=item;
    pthread_mutex_unlock(&b.bufflock);
    sem_post(&b.full);
	}

}
void *consumer(void *arg)
 {  
	int k;
	int cons;
	int i=*(int *)arg;
	while(1)
	{
      		sem_wait(&b.full);
		sleep(1);
		pthread_mutex_lock(&b.bufflock);
		cons=b.buffer[(b.out++)%B_SIZE];
		printf("-----------------------------------------Comsumer %d consumed item %d\n",i+1,cons);
		pthread_mutex_unlock(&b.bufflock);
		sem_post(&b.empty);
	}
}
