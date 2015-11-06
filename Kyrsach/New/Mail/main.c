#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define Ng 8
#define Nl 30
#define Nm  40
struct lass{
 int x,y;
}loshads[Nl];

int iterator[Ng];
sem_t gorodaAs,losha[9];
void add(int n){
    sem_wait(&losha[n]);
    iterator[n]++;
    sem_post(&losha[n]);
}
void deletee(int n){
    if(iterator[n]<=0) return;
    sem_wait(&losha[n]);
    iterator[n]--;
    sem_post(&losha[n]);
}
void *thread_Men(void *in){
   int e= (int)in;
   for(;;){
    int r = rand()%100;
    if (r>10){
        add(rand()%8);
    }
    usleep(9000000);
    }
}
int lenloshad(int n){
int t,ret=0;
    for (t=0;t<Nl;t++)
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
            printf("\033[%d;0H%d) %2d людей ожидает, свободных лощадей %3d ",i+2,i+1, iterator[i] ,lenloshad(i) );
        }
        usleep(1000000);

        k++;
        printf("\033[24;0H Время: %4d секунд", k);
    }
}
void beg(int l,int l2){
int u = l2 - l;
int i,j,y;

if(u<0) y = 1;
else y = -1;
 l  +=2;
    for(i=0;i<8;i++){
        printf("\033[%d;%dH&",l,45+i);
        usleep(150000);
        printf("\033[%d;%dH  ",l,45+i);
    }
    int c=0;
    while(abs(u)!=c){
    l -= y;
        printf("\033[%d;%dH&",l,45+i);
        usleep(150000);
        printf("\033[%d;%dH  ",l,45+i);
        c++;
    }
    for(i=8;i>0;i--){
        printf("\033[%d;%dH&",l,45+i);
        usleep(150000);
        printf("\033[%d;%dH  ",l,45+i);
    }
}
void *loshad(void *in){
 int n = (int) in;
 int t,t2;
 loshads[n].x = rand()%Ng;
 usleep(20000);
 for (;;){
         t = rand()%Ng;
            deletee(loshads[n].x);
            printf("\033[23;0HЛощадь выехала из A(%d) в пункт В(%d).. ",loshads[n].x,t);
                sem_wait(&losha[(loshads[n].x)]);
            //loshads[n].x =-1;
            beg( loshads[n].x ,t);
            t2 = abs(loshads[n].x-t);

            loshads[n].x =t ;
                   sem_post(&losha[(loshads[n].x)]);

          //  beg(iterator[n],rand()%8);


       //     printf("\033[23;0H                                        ",n,goroda[n].y);
       //     printf("\033[23;0Hлощадь выехала из A(%d) в пункт В(%d).. ",n,goroda[n][0].y);
       usleep((3000000)*t2);
 }
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
