#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char text[100];
    int  handles[2],i;
    handles[0] = open(argv[1], O_RDONLY, NULL);
	handles[1] = dup(handles[0]);
	handles[2] = open(argv[1], O_RDONLY, NULL);

    lseek(handles[0], 10, SEEK_SET);

    for(i = 0; i < 3; i++)
	{
		read(handles[i], text, 7);
		//strcat(text, "\n");
		write(0, text , strlen(text));
	}

	printf("\nhandles number:\n");
	for(i = 0; i < 3; i++)
	{
		printf("handles[%d] = %d\n", i+1, handles[i]);
	}
    return 0;

}
