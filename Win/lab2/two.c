#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int main(int argc, char* argv[])
{
char text[100];
	DWORD len, actlen;
	int i;
	HANDLE handles[3];
	handles[2] = GetStdHandle(STD_OUTPUT_HANDLE);
	handles[0] = CreateFile( argv[1], GENERIC_READ, FILE_SHARE_READ,0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,0);
	handles[1] = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ,0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,0);

	for(i=0;i<3;i++)
	{
		ReadFile(handles[i], text, 7, &actlen, NULL);
		WriteFile(handles[2], text, strlen(text), &len, NULL);

	}
	printf("\nhandles number:\n");
	for(i=0;i<3;i++)
	{
		printf("handles[%d] = %d\n", i, handles[i]);
	}
	return 0;
}
