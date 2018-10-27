#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

void *reader(void *);
void *writer (void *);
int readcount=0;
pthread_mutex_t wsem,mutex;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wsem = PTHREAD_MUTEX_INITIALIZER;

main()
{
	int a=1,b=1;
	system("clear");
	pthread_t r,w,r1,w1;
	pthread_create(&r,NULL,reader,(void *)a);
	a++;
	pthread_create(&w,NULL,writer,(void *)b);
	b++;
	pthread_create(&r1,NULL,reader,(void *)a);
	pthread_create(&w1,NULL,writer,(void *)b);
	pthread_join(r,NULL);
	pthread_join(w,NULL);
	pthread_join(r1,NULL);
	pthread_join(w1,NULL);
	printf("\nTERMINATED\n");
}
void *reader(void *arg)
{
	int c=(int)arg;
	printf("\nreader %d is created",c);
	sleep(1);
	pthread_mutex_lock(&mutex);
	readcount++;
	if(readcount==1)
		pthread_mutex_lock(&wsem);
		pthread_mutex_unlock(&mutex);
		
	printf("\nreader %d is reading",c);
	sleep(2);
	printf("\nreader %d finished reading",c);
	pthread_mutex_lock(&mutex);
	readcount--;

	if(readcount==0)
	pthread_mutex_unlock(&wsem);
	pthread_mutex_unlock(&mutex);
}
void *writer(void *arg)
{
	int c=(int)arg;
	printf("\nwriter %d is created",c);
	sleep(1);
	pthread_mutex_lock(&wsem);
	printf("\nwriter %d is writing",c);
	sleep(1);
	printf("\nwriter %d finished writing",c);
	pthread_mutex_unlock(&wsem);
}

