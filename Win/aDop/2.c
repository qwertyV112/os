#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

int main()
{
int actlen;
char *FileName = "2.exe";
char *pm;
HANDLE hmemory, hout;

 hout = GetStdHandle(STD_OUTPUT_HANDLE);
 hmemory=CreateFileMapping((HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, 16000, "SHAREMEM_MYY");
 if(hmemory ==0){
 WriteFile (hout, "Error memory...", 15, &actlen, NULL);
 return 0;
 }
pm = MapViewOfFile(hmemory, FILE_MAP_WRITE, 0,0, 0);
if(pm == NULL){
 WriteFile (hout, "Error memory...", 15, &actlen, NULL);
 return 0;
}

strcpy(pm, "hell0 world...");
Sleep(1500);
UnmapViewOfFile(pm);
return 0;
}
