//WORKING
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t empty,full;
pthread_mutex_t m;
int max_buffer;
int buffer[100];

void *producer(void *arg)
{
  int c=0,item=0;
  while(c<max_buffer)
  {
    sem_wait(&empty);
    pthread_mutex_lock(&m);
    item++;
    buffer[c]=item;
    printf("\nProduced:%d",item);
    pthread_mutex_unlock(&m);
    sem_post(&full);
    c++;
  } 
}

void *consumer(void *arg)
{
  int c=0,item;
  while(c<max_buffer)
  {
    sem_wait(&full);
    pthread_mutex_lock(&m);
    item=buffer[c];
    printf("\nConsumed:%d",item);
    pthread_mutex_unlock(&m);
    sem_post(&empty);
    c++;
  } 
}

int main()
{
  printf("Enter max number of items");
  scanf("%d",&max_buffer);
  sem_init(&full,0,0);
  sem_init(&empty,0,max_buffer);
  pthread_mutex_init(&m,NULL);
  pthread_t p,c;
  pthread_create(&p,NULL,producer,NULL);
  pthread_create(&c,NULL,consumer,NULL);
  pthread_join(p,NULL);
  pthread_join(c,NULL);
  sem_destroy(&full);
  sem_destroy(&empty);
  pthread_mutex_destroy(&m);  
  printf("\n");
}
