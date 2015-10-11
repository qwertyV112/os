#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int len;
	char fname[ ]="myresult.txt";
	int fhandle;
	char text[100];
	write(1,"Please, input some text: ",25);
	len = read(0,text,100);
	write(1,text,len);

	fhandle=open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	write(fhandle, text, strlen(text));
	close(fhandle);
	return 0;
}
