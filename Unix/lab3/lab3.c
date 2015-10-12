#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define ERROR -1
#define NORM 0
int main(){
    char text[100] = "\n";
    char FileName[]="open.txt";
    int hbloc,i=0;
    struct flock lock = {F_WRLCK,SEEK_SET,0,0};

    int fhandle = open(FileName, O_RDWR, NULL);
    if(fhandle== ERROR ){
    printf("Error:not file/invalid file....\n");
    return 0;
    }
     initscr();
   	while(1!=2){
   	 hbloc = fcntl(fhandle, F_SETLK, &lock);
            if (hbloc == ERROR)
            {
                move(15,12); addstr("File blocked...");
            }
            else{
            if (i<1)
                {
                read(fhandle,text,100);
                move(0,0);
                write(0,text,strlen(text));
                }
                i++;
            }
            usleep(900000);
            refresh();
   	}
   	endwin();
/*


        */

}
