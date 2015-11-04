#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define Ng 8
#define Nl 20
#define Nm  40
struct lass{
 int x,y;
}loshads[Nl];

int interator[Ng];
sem_t gorodaAs,losha[9];
void add(int n){
    sem_wait(&losha[n]);
   // goroda[n].interator++;
    sem_post(&losha[n]);
}
void *thread_Men(void *in){
   int e= (int)in;
   for(;;){
    int r = rand()%100;
    if (r>10){
        add(rand()%8);
    }
    usleep(20000000);
    }
}
int lenloshad(int n){
int t,ret=0;
    for (t=0;t<Ng;t++)
    {
        if (loshads[t].x==n) ret++;
    }
    return ret;
}
void Writer(){
int i,k=0;
    for(;;){
         printf("\033[0;0HНомер города");
        for(i=0; i<Ng;i++){
            printf("\033[%d;0H%d) %d людей ожидает, свободных лощадей %d ",i+2,i+1, 4 ,lenloshad(i) );
        }
        usleep(1000000);
        k++;
        printf("\033[24;0H Время: %4d секунд", k);
    }
}
void *loshad(void *in){

}
int main()
{
int i;
    pthread_t cd[101];
    setbuf(stdout,NULL);

//         goroda=malloc(sizeof(struct gorod)*9);
//         loshads=malloc(sizeof(struct lass*)*20);
    for(i=0;i<Nl;i++)
    {
        pthread_create( &cd[i], NULL, loshad, (void*)i);
        sem_init(&losha[i],0,3);
    }
            pthread_create( &cd[100], NULL, Writer, NULL);
    for (i=0;i<Nm;i++)
        pthread_create( &cd[Nl+i], NULL, thread_Men, NULL);
        while(1){}
    getchar();
}
