#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int mass[3]={0,0,0};
int queue[20],iterat=0;
sem_t refill,pay,print,massAsses;

void car(void* arg)
{
int nomer=((int*)arg)[0],position;
printf("\033[%d;2HСоздал",nomer);
sem_wait(&refill);
printf("\033[%d;2HЗаехал",nomer);
usleep(2000000);
sem_post(&refill);
printf("\033[%d;2HВыехал",nomer);
}

void ini()
{
sem_init(&refill,0,3);

printf("\033[2J\033[1;1H");
setbuf(stdout,NULL);
}
int main()
{

ini();
pthread_t tid[30];

int N=15,i;
int mas[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
for(i=0;i<N;i++)
pthread_create(&tid[i], NULL, car, mas+i);

getchar();
getchar();
return 0;
}
