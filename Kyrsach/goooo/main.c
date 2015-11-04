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
}*goroda;
int iterator[9];
sem_t gorodaAs,losha[9];

void add(int n){
    sem_wait(&losha[n]);
    iterator[n]++;
    goroda[n][rand()%5].x = n;
    goroda[n][rand()%5].y = rand()%9;
    sem_post(&losha[n]);

}

int  deletee(int n){

    if(iterator[n]==0) {return -1;}
    sem_wait(&losha[n]);
        iterator[n]--;
    sem_post(&losha[n]);
}
void *thread_Men(void *in){
   // srand(time(NULL));
   int e= (int)in;
   for(;;){
    int r = rand()%100;
    if (r>10){
        add(rand()%8);
    }
    usleep(20000000);
    }
}
void Writer(){
int i,j, k=0;
    for (;;){
        for (i=0;i<N;i++){
           printf("\033[%d;0H                                                  ",i);
           printf("\033[%d;0H%d) %d людей ожидают ",i,i,iterator[i]);
        }
        usleep(1000000);
        printf("\033[24;0HВремя: %d секунд",k);
        k++;
    }

       printf("\033[24;0HВремя: %d\033[0K\033[36;7m секунд",k);
    }
void *loshad(void * in){
int n = (void*)in;
usleep(200000);
        for(;;){
        printf("\033[23;0H                                        ",n,goroda[n][0].y);
            printf("\033[23;0Hлощадь выехала из A(%d) в пункт В(%d).. ",n,goroda[n][0].y);
            deletee(n);
            usleep(2000000);

        }
}
int main()
{
int i;
    setbuf(stdout,NULL);
pthread_t cd1[N];
pthread_t cd[101];
    goroda=malloc(sizeof(struct Positions*)*9);
    for(i=0;i<N;i++)
    {
        goroda[i]=malloc(sizeof(struct Positions)*5);
        iterator[i]=0;
            pthread_create( &cd1[i], NULL, loshad, (void*)i);
        sem_init(&losha[i],0,3);
    }
        pthread_create( &cd[100], NULL, Writer, NULL);
    for(i=0;i<N1;i++)
    {
        pthread_create( &cd[i], NULL, thread_Men, NULL);

    }

    while(1){}
    getchar();
}
//индитификатор
//атрибутная запись потока
//pthread_self()
