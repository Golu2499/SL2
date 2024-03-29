#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <semaphore.h>
#include "monitor.h"

//semaphores to implement monitor
sem_t mutex;
sem_t next;
//count varaible for philosophers waiting on semaphore next
int next_count = 0;

//implementing condition variable using semaphore
//semaphore and integer variable replacing condition variable
typedef struct
{
	sem_t sem;
	//count variable for philosophers waiting on condition semaphore sem
	int count;
}condition;
condition x[N];

//state of each philosopher(THINKING, HUNGRY or EATING)
int state[N];

//turn variable corresonding to each chopstick
//if philosopher i wants to each the turn[i] and turn[LEFT]must be set to i
int turn[N];

//wait on condition
void wait(int i)
{
	x[i].count++;
	if(next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
	sem_wait(&x[i].sem);
	x[i].count--;
	//	printf("\nX.count -> %d",x.count);
}

//signal on condition
void signal(int i)
{
	if(x[i].count > 0)
	{
		next_count++;
		//signal semaphore x[i].sem
		sem_post(&x[i].sem);
		//wait semeaphore next
		sem_wait(&next);
		next_count--;
	}
}
void test(int i)
{
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING && turn[i] == i && turn[LEFT] == i)
	{
		state[i] = EATING;

		//signal on condition
		signal(i);

		/*	printf("\nNext Count -> %d, X_count -> %d,state[%d] -> %d,state[%d] -> %d,state[%d] -> %d",
			next_count,x[i].count,i,state[i],LEFT,state[LEFT],RIGHT,state[RIGHT]);*/

	}
}

void take_chopsticks(int i)
{
	//wait semaphore mutex
	sem_wait(&mutex);
	state[i] = HUNGRY;
	test(i);
	while(state[i] == HUNGRY)
	{
		//printf("\nThread %d is waiting on condition",i);

		//wait on condition
		wait(i);
	}
	if(next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
}

void put_chopsticks(int i)
{
	//wait semaphore mutex
	sem_wait(&mutex);
	state[i] = THINKING;
	//set turn variable pointing to LEFT and RIGHT philosophers
	turn[i] = RIGHT;
	turn[LEFT] = LEFT;

	test(LEFT);
	test(RIGHT);

	if(next_count > 0)
	{
		//signal semaphore next
		sem_post(&next);
	}
	else
	{
		//signal semaphore mutex
		sem_post(&mutex);
	}
}

void initialization()
{
	int i;
	sem_init(&mutex,0,1);
	sem_init(&next,0,0);
	for(i = 0;i < N;i++)
	{
		state[i] = THINKING;
		sem_init(&x[i].sem,0,0);
		x[i].count = 0;
		turn[i] = i;
	}
	//setting turn variables such that Philosophers 0,2 or 4 can grab both chopsticks initially
	turn[1] = 2;
	turn[3] = 4;
	turn[6] = 0;

}
