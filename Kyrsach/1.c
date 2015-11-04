#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define N 8
#define N1 48

struct Positions{
    int x, y;
}**goroda;
int iterator[9];
sem_t mens[],losha[];


void add(int n,struct Positions zak)
{
    goroda[n][iterator[n]++]=zak;
}
struct Positions udal(int n)
{
    struct Positions zak=goroda[n][0];
    int i;
    for(i=0;i<iterator[i]-1;i++)
    goroda[n][i]=goroda[n][i+1];
    return zak;
}
void *loshadi(void *iu){

    }
void *writer(void *iu)
{
int i,j,k=0;
    for(;;)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<iterator[i];j++)
            {
                printf("\033[%d;%dH%d %d|",i+2,j*4+3,goroda[i][j].x,goroda[i][j].y);
            }
        }
        usleep(1000000);
    }
};

void *thread_Men(void *in){
    int k = (int*)in;
    struct Positions pos={3,5};
    int t=rand()%9;
    add(t,pos);
    //for(;;);
    usleep(2000000);
    udal(t);
}


int main()
{
    int i;
    pthread_t cd[1000];
    goroda=malloc(sizeof(struct Positions*)*9);
    for(i=0;i<8;i++)
    {
        goroda[i]=malloc(sizeof(struct Positions)*20);
        iterator[i]=0;
    }
    pthread_create( &cd[30], NULL, writer, NULL);

     for(i=0;i<N1;i++){
        int t= pthread_create( &cd[i], NULL, loshadi, (void*)i);
     }
    for(i=0;i<N;i++){
        int t= pthread_create( &cd[i+N1], NULL, thread_Men, (void*)i);
     }
getchar();
getchar();
}
//индитификатор
//атрибутная запись потока
//pthread_self()


//sem_wait // заблокировать, уменьшить сем на 1, ожидает если симофор  = 0
//sem_post // разболкировать
//sem_init
