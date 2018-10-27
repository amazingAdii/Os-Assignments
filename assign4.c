#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 10

pthread_mutex_t mutex;
sem_t empty,full;

int buffer[BUFFER_SIZE];
int counter;

pthread_t tid;

void *producer();
void *consumer();

void insert_item(int);
int remove_item();

void initilize()
{
 pthread_mutex_init(&mutex,NULL);
 sem_init(&full,0,0);
 sem_init(&empty,0,BUFFER_SIZE);
}


void *producer()
{
 int item,wait_time;
 wait_time=rand()%5;
 sleep(wait_time)%5;
 item=rand()%10;
 sem_wait(&empty);
 pthread_mutex_lock(&mutex);
 printf("Producer produce %d\n\n",item);
 insert_item(item);
 pthread_mutex_unlock(&mutex);
 sem_post(&full);
}

void *consumer()
{
 int item,wait_time;
 wait_time=rand()%5;
 sleep(wait_time);
 sem_wait(&full);
 pthread_mutex_lock(&mutex);
 item=remove_item();
 printf("Consumer consume %d\n\n",item);
 pthread_mutex_unlock(&mutex);
 sem_post(&empty);
}

void insert_item(int item)
{
 buffer[counter++]=item;
}

int remove_item()
{
 return buffer[--counter];
}

int main()
{
 int n1,n2;
 int i;
 printf("Enter number of Producers");
 scanf("%d",&n1);
 printf("Enter number of Consumers");
 scanf("%d",&n2);
 initilize();
 for(i=0;i<n1;i++)
  pthread_create(&tid,NULL,producer,NULL);
 for(i=0;i<n2;i++)
  pthread_create(&tid,NULL,consumer,NULL);
 sleep(5);
 exit(0);
}

