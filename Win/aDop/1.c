#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  main()
{
    char *pb, st[20];
    HANDLE hmem;
    int i;
    hmem=OpenFileMapping(FILE_MAP_READ, FALSE,"SHAREMEM_MYY”");
    if (hmem= =0)
    {printf(”rror OpenSharedMem with RC=%ld\n”, GetLastError());
    getchar(); exit(0);}
    pb=MapViewOfFile(hmem, FILE_MAP_READ,0,0,0);
    if (pb==NULL)
    {
    printf("Error Mapping SharedMem with RC=%ld\n", GetLastError());
    getch();
    exit(0);
    }
    for (i=0;i<10;i++ )
    {
     strncpy(st, pb, 20); st[19]='\0';
     printf(“%s\n”, st); Sleep(2000);
     }
    UnmapViewOfFile(pb);
    CloseHandle(hmem);
}
