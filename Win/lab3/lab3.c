#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <string.h>
    HANDLE hin,hout,fileHandle;
void gotoXY(int x,int y){
	COORD pos;
	pos.X =x;
	pos.Y =y;
	SetConsoleCursorPosition(hout, pos);
	SetConsoleTextAttribute (hout, FOREGROUND_GREEN);
}
int main(){

    char text[100] = "\n";
    char FileName[]="open.txt";
    int hbloc;
    OVERLAPPED overlapped;


    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    fileHandle = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ,0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hout==INVALID_HANDLE_VALUE)
	    {
			printf("Error:not file/invalid file....");
			return 0;
		}
		 hbloc = LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK | LOCKFILE_FAIL_IMMEDIATELY, NULL, 1, 0, &overlapped);
   	while(1!=2){

   	 printf("%d\n", hbloc);
            /*if (hbloc == ERROR)
            {
                gotoXY(12,30); addstr("File blocked...");
            }
            else{
            if (i<1)
                {
                read(fhandle,text,100);
                move(0,0);
                write(0,text,strlen(text));
                }
                i++;
            }*/
            Sleep(90);

   	}

}
