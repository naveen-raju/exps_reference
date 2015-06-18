#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct __data {
	int x;
	pthread_mutex_t lock;
} DATA, *PDATA;

void *f1(void *arg)
{
	PDATA dp = (PDATA) arg;
	pthread_mutex_lock(&dp->lock);
	printf("this thread sleeps fro 10 secs\n");
	dp->x = 100;
	printf("%d", dp->x);
	fflush(stdout);
	sleep(10);
	pthread_mutex_unlock(&dp->lock);
}

void *f2(void *arg)
{
	PDATA dp = (PDATA) arg;
	pthread_mutex_lock(&dp->lock);
	printf("this thread sleeps fro 20 secs\n");
	dp->x = 200;
	printf("%d", dp->x);
	fflush(stdout);
	sleep(10);
	sleep(10);
	pthread_mutex_unlock(&dp->lock);
}

int main()
{
	pthread_t t1, t2;
	PDATA dp = malloc(sizeof(DATA));

	pthread_mutex_init(&dp->lock, NULL);

	pthread_create(&t1, NULL, f1, dp);
	pthread_create(&t2, NULL, f2, dp);

	pthread_mutex_destroy(&dp->lock);
	return 0;

}
