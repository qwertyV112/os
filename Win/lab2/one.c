#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    HANDLE fWriter[4];
    char text[100]="\n";
    DWORD actlen;
    fWriter[0] = GetStdHandle(STD_INPUT_HANDLE);
    fWriter[1] = GetStdHandle(STD_OUTPUT_HANDLE);
    fWriter[2] = CreateFile(argv[1], GENERIC_WRITE, 0 ,0 , CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    WriteFile(fWriter[1],"Please, input some text: ",25, &actlen, NULL);
    ReadFile(fWriter[0], text, 100, &actlen, NULL);
    printf("\n%s",text);
    WriteFile(fWriter[2], text, strlen(text), &actlen, NULL);
    CloseHandle(fWriter[2]);
    return 0;
}
