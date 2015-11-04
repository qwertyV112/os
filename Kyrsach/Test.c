#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t sem[10];
int kol=0;				// номер потока
int t=3;					// отступ от верха
int N;					// кол-во студентов
int M;					// время для подготовки
int r=20;				// кол-во студентов в столбце
void clearer(int i,int j)			// функция очистки и сброса цвета
{
    printf("\033[%d;%dH\033[m                        ",i,j);
}
void student(void* arg)			// поток студент
{
    int id=kol++;				// id студента
    int x=id%r+t;			// положение по координате Х
    int y=2+25*(id/r);			// положение по координате Y
    (id<10)?y++:0;			// увеличение Y на 1, если id<10
    int mark;				// оценка
    sem_wait(&(sem[2]));		// блокировка семафора для вывода на экран
    clearer(x,y);
    printf("\033[%d;%dH%d \033[32;7mЖдет за дверью",x,y,id);
    sem_post(&(sem[2]));		// освобождение семафора для вывода на экран
    sem_wait(&(sem[0]));  		// блокировка семафора ограничитель на вход
        sem_wait(&(sem[2])); 		// блокировка семафора для вывода на экран
        clearer(x,y);
        printf("\033[%d;%dH%d \033[7;33mГотовится к ответу",x,y,id);
        sem_post(&(sem[2]));		// освобождение семафора для вывода на экран
        IdiGotovsu:
        usleep(M*2000000);		// подготовка
            sem_wait(&(sem[1]));		// блокировка семафора сдача экзамена
                sem_wait(&(sem[2]));	// блокировка семафора для вывода на экран
                clearer(x,y);
                printf("\033[%d;%dH%d \033[5;42mОтвечает на билет",x,y,id);
                sem_post(&(sem[2]));	// освобождение семафора для вывода на экран
                usleep(M*1000000);		// сдача экзамена
                mark=rand()%5;		// случайная оценка от 0 до 4
                if(mark==1)			// пересдача
                    {
                        sem_post(&(sem[1]));
                        sem_wait(&(sem[2]));		// блокировка семафора для вывода на экран
                        clearer(x,y);
                        printf("\033[%d;%dH%d \033[34;42mПовторно готовится",x,y,id);
                        sem_post(&(sem[2]));	        // освобождение семафора для вывода на экран
                        goto IdiGotovsu;		//переход к IdiGotovsu, чтобы попытаться еще раз
                    }
                    else
                    if(mark==0)			//выгнан с экзамена
                    {
                        sem_post(&(sem[1]));		   // освобождение семафора сдача экзамена
                        sem_post(&(sem[0])); 	     // освобождение семафора ограничитель на вход
                        sem_wait(&(sem[2])); 	   	// блокировка семафора для вывода на экран
                        clearer(x,y);
                        printf("\033[%d;%dH%d \033[7;31mВыгнан с экзамена",x,y,id);
                        sem_post(&(sem[2]));	         // освобождение семафора для вывода на экран
                        return;
                    }
                sem_wait(&(sem[2]));		// блокировка семафора для вывода на экран
                clearer(x,y);
                printf("\033[%d;%dH%d \033[34;7mОценка %d",x,y,id,mark+1);
                sem_post(&(sem[2]));	       // освобождение семафора для вывода на экран
            sem_post(&(sem[1]));		      // освобождение семафора сдача экзамена
    sem_post(&(sem[0]));		      // освобождение семафора ограничитель на вход

}
int main()
{
    printf("\033[2J\033[1;1H");			// очистка экрана
    sem_init(&sem[0], 0,6);			// инициализация
    sem_init(&sem[1], 0,1);
    sem_init(&sem[2], 0,1);
    int i=0;
    printf("\033[1;1H\033[0KВведите кол-во студентов:");
    scanf("%d",&N);
    printf("\033[1;1H\033[0KВведите среднее время для подготовки ответа студента:");
    scanf("%d",&M);
    printf("\033[2J\033[1;1H");
    for(i=0;i<N/(r+1)+1;i++)
    printf("\033[2;%dH\033[0K\033[36;7mid Состояние студента",2+i*25);
    pthread_t tid[30];
    setbuf(stdout,NULL);			//отмена буферизации
    for(i=0;i<N;i++)				//запуск потоков студентов
    pthread_create(&tid[i], NULL, student, NULL);
    getchar();
    getchar();
    return 0;
}
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

        for(;;){
        srand(time(NULL));

            printf("\033[23;0Hлощадь выехала из A(%d) в пункт В(%d).. ",n,goroda[n][0].y);
            deletee(goroda[n][0].x);
            usleep(20000000);
            printf("\033[23;0H                                         ",n,goroda[n][0].y);
        }
}
int main()
{
int i,j;
    setbuf(stdout,NULL);
pthread_t cd1[N];
pthread_t cd[101];
    goroda=malloc(sizeof(struct Positions*)*9);
    for(i=0;i<N;i++)
    {
        goroda[i]=malloc(sizeof(struct Positions)*5);
        iterator[i]=0;
            pthread_create( &cd1[i], NULL, loshad, (void*)i);
        sem_init(&losha[i],0,5);
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
