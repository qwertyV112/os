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
	DWORD actlen;
    char text[100] = "\n";
    int w;
    char FileName[]="open.txt";
    int hbloc;
    OVERLAPPED overlapped;
overlapped.hEvent = 0;

    hout=GetStdHandle(STD_OUTPUT_HANDLE);
    fileHandle = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ,0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if(hout==INVALID_HANDLE_VALUE)
	    {
			printf("Error:not file/invalid file....");
			return 0;
		}
		 hbloc = LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK | LOCKFILE_FAIL_IMMEDIATELY, NULL, 1, 0, &overlapped);
   if(hbloc==INVALID_HANDLE_VALUE)
	{
		//erLockMessege(displayHandle);

	}
         LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK, NULL, 1, 0, &overlapped);
   	while(1!=2){
            Sleep(90);
            ReadFile(fileHandle,text,100,&actlen, NULL);
            gotoXY(25,5);WriteFile(hout,text,strlen(text),&actlen, NULL);
            return 0;

   	}

}
