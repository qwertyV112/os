#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#define N 8
#define N1 48

struct Positions{
    int x, y;
};
struct Gorod{
    pthread_t Pid;
    struct Positions poz;
    struct Positions pozt;
};
struct Loshads {
    pthread_t Pid;
    struct Positions poz;
    struct Positions pozt;
    int Sleep;
    bool flagZ;
    bool flagB;
    int x;

};
struct Men {
    pthread_t Pid;
    bool flagZ;
    bool flagB;
    int x;
    int y;

};
struct Gorod gorod[N];
struct Loshads loshad[N1];
struct Men men[N];
//void PozitionLoshad(struct *Positions,struct Positions);
void creat(){
    int i,j,q=0;
        for(i=0;i<(N/2);i++){
            for(j=0;j<(N/2);j++){
            gorod[q].poz.x = 1+i*7;
            gorod[q].poz.y = 7+j*20;
            gorod[q].pozt.x =i; gorod[q].pozt.y =j;
                move(gorod[q].poz.x ,gorod[q].poz.y);
                addch('A');
                q++;
            }

    }
    return;
    }/*
void PozitionLoshad(struct Positions *begins,struct Positions ends){
int i;
    for(i=0;i<20;i++){
        if ( (begins.x)!=ends.x){
                if(begins.x>ends.y) *begins.x--;
                else *begins.x++;
        }
        if ( *begins.y!=ends.y){
                if(begins.y>ends.y) *begins.y--;
                else *begins.y++;
        }

            if(*begins.x!=ends.x || *begins.y!=ends.y ){
            move(*begins.x,*begins.y);
             addch('&');
             usleep(200000);


             //
            }
refresh();
move(*begins.x,*begins.y);
addch(' ');
    }
    return;
}*/

void *loshadi(void *iu){
    int u = (int)iu;
    loshad[u].x = rand()%N;
    loshad[u].poz.x= gorod[(loshad[u].x)].poz.x;
    loshad[u].poz.y= gorod[(loshad[u].x)].poz.y;
    //loshad[u].flagB = true;
    int i;
    while(1){
        for (i=0;i<N;i++){
            if (loshad[u].x == men[i].x){
                    if (men[i].flagZ){
                        if(!men[i].flagB){
                            men[i].flagB = true;
                            men[i].flagZ = false;
                            //бег)
                            //------------------------
                                        int j;
                                        int x = loshad[u].poz.x;
                                        int y = loshad[u].poz.y;
                                        int x1 = gorod[(men[i].y)].poz.x;
                                        int y1 = gorod[(men[i].y)].poz.y;
                                        for(j=0;j<40;j++){
                                       // Cler();
                                                        if ( x!=x1){
                                                                if(x>x1) x--;
                                                                else x++;
                                                        }
                                                        if ( y!=y1){
                                                                if(y>y1) y--;
                                                                else y++;
                                                        }

                                                            if(x!=x1 || y!=y1 ){
                                                            move(x,y);
                                                             addch('&');
                                                             usleep(200000);


                                                             //
                                                            }
                                                        refresh();
                                                        move(x,y);
                                                        addch(' ');
                                                        Cler();
                                                        //Cler();
                                        }
                                                                    men[i].flagB = false;
                                                                    men[i].flagZ = false;
                                                                    men[i].x = men[i].y;
                                                                    loshad[u].x =men[i].y;
                                                                    loshad[u].poz.x= gorod[(loshad[u].x)].poz.x;
                                                                    loshad[u].poz.y= gorod[(loshad[u].x)].poz.y;

                                            usleep(30000000);
                                                    pthread_join(loshad[u].Pid,NULL);
                            //------------------------

                        }
                    }
                }
              //  Cler();
            }
        }
        usleep(20000);
    }


void *thread_Men(void *in){
    int k = (int)in;
    men[k].x =rand()%N;
    men[k].flagB =false;
    men[k].flagZ =false;
   srand(time(NULL));
    while(1){
//Cler();
    int d = rand()%100;
    if (d<10){
        if (!men[k].flagB){
            if (!men[k].flagZ){
                men[k].y = rand()%N;
                men[k].flagZ = true;
            }
        }

        }
        //usleep(2000);
    }
}


void Cler();

void Cler(){
 int i;
        for(i=0;i<N;i++){
                move(gorod[i].poz.x ,gorod[i].poz.y);
                addch('A');
    }
    return;
}



int main()
{

     initscr();
curs_set(0);
     creat();
     int i;
     for(i=0;i<N1;i++){
        int t= pthread_create( &loshad[i].Pid, NULL, loshadi, (void*)i);
     }
    for(i=0;i<N;i++){
        int t= pthread_create( &men[i].Pid, NULL, thread_Men, (void*)i);
     }

     while(1){
        usleep(20000);
        refresh();
     }

     for( i=0;i<N1;i++){
      pthread_exit( loshad[i].Pid);
     }
     for( i=0;i<N;i++){
      pthread_exit( men[i].Pid);
     }
     endwin();
return 0;
}
//индитификатор
//атрибутная запись потока
//pthread_self()


//sem_wait // заблокировать, уменьшить сем на 1, ожидает если симофор  = 0
//sem_post // разболкировать
//sem_init
