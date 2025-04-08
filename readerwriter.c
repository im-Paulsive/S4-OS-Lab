#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdint.h>
sem_t mutex,writeblock;
int data=0,readcount=0;

void* reader(void* arg)
{
    int f=*(int*)arg;
    sem_wait(&mutex);
    readcount++;
    if(readcount==1)
        sem_wait(&writeblock);
    sem_post(&mutex);
    
    printf("reader%d reads %d\n",f,data);
    sleep(1);
    
    sem_wait(&mutex);
    readcount--;
    if(readcount==0)
        sem_post(&writeblock);
    sem_post(&mutex);
    return NULL;
}    
void* writer(void* arg)
{
    int f=*(int*)arg;
    sem_wait(&writeblock);
    data++;
    printf("writer %d wrote data %d\n",f,data);
    sleep(1);
    sem_post(&writeblock);
    return NULL;
}
int main() {
   
   pthread_t r[5],w[5];
   sem_init(&mutex,0,1);
   sem_init(&writeblock,0,1);
   
   for(int i=0;i<5;++i)
   {
       pthread_create(&w[i],NULL,writer,&i);
       pthread_create(&r[i],NULL,reader,&i);
   }
   for(int i=0;i<5;++i)
   {
       pthread_join(w[i],NULL);
       pthread_join(r[i],NULL);
   }
    sem_destroy(&mutex);
    sem_destroy(&writeblock);

    return 0;
}
