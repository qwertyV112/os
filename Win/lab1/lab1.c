#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int main()
{
	HANDLE hout;
	HANDLE hinp;
	HANDLE fhandle;
	char buffer[100] = "\n";
	DWORD actlen,len;
	char fname[]="myresult.txt";

	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	hinp=GetStdHandle(STD_INPUT_HANDLE);
	printf("INPUN NAMER =%d\nOUTPUT NAMER =%d\n",hout,hinp); // fflush(stdout);
	WriteFile (hout, "Please, input some text: ", 24, &len, NULL);
	ReadFile(hinp, buffer+1, len+1, &actlen, NULL);
	WriteFile (hout, buffer, 100, &actlen, NULL);


	fhandle=CreateFile(fname, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

	WriteFile(fhandle, buffer, strlen(buffer), &actlen, NULL);
    CloseHandle(fhandle);
	return 0;
}
/*{


	DWORD len, actlen;
	HANDLE outHandle, inHandle ;
	char buffer[100] = "\n";
	BOOL readed;
	outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
 	inHandle = GetStdHandle(STD_INPUT_HANDLE);
	if(outHandle == INVALID_HANDLE_VALUE || inHandle == INVALID_HANDLE_VALUE)
	{
		printf("Error of getting input or/and input handles!");
		_getch();
		return 0;
	}
	printf("%d - this is input handle\n%d - this is output handle...\n", inHandle, outHandle);
	WriteFile (outHandle, "Please, input some text!", 24, &len, NULL);
	readed = ReadFile(inHandle, buffer+1, len+1, &actlen, NULL);
	if(!readed)
	{
		printf("Error of reading!");
		_getch();
		return 0;
	}
	WriteFile (outHandle, buffer, 100, &actlen, NULL);

	_getch();
	return 0;
}*/
