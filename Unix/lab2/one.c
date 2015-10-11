#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char text[100];
    int fWriter = open(argv[1],O_WRONLY | O_CREAT, 0600);
    write(1,"Please, input some text: ",25);
    read(1,text,100);
    write(fWriter,text,strlen(text));
    close(fWriter);
    return 0;

}
