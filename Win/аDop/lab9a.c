#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

COORD textCoord;
HANDLE memory_handle, display;

void showMessage(int X, int Y, int colors, char* message)
{
		textCoord.X = X;
		textCoord.Y = Y;
		SetConsoleCursorPosition(display, textCoord);
		SetConsoleTextAttribute(display, colors);
		printf("%s\n", message);
}

void toNormalState()
{
	SetConsoleTextAttribute(display, 112);
	system("cls");
	CloseHandle(display);
	CloseHandle(memory_handle);
}


void main()
{
	int len, actlen;
	STARTUPINFO startInfo;
	PROCESS_INFORMATION procInfo;
	char *comStr = "lab9b.exe", *regName = "COMMON_MEMORY", *baseAdress;
	
	
	display = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	showMessage(0, 3, 121, "Program 1 messages:");
	memory_handle = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0, 16000, regName);
	if( memory_handle == 0)
	{
		showMessage(0,5, 124, "Error of creating common memory!");
		_getch();
		toNormalState();
		return;
	}
	showMessage(0,5, 113, "Common region of memory was created!");
	baseAdress = MapViewOfFile(memory_handle, FILE_MAP_WRITE, 0,0, 0);
	if(baseAdress == NULL)
	{
		showMessage(0,5, 124, "Error of getting common memory!");
		_getch();
		toNormalState();
		return;
	}
	showMessage(0,6, 113, "Adress of beginning of common memory region was getting!");
	strcpy(baseAdress, "Hello, bro! I'm writing this message and putting it in our common memory that you will can read it and output on screen to master. Good luck.");
	showMessage(0,7, 113, "In common memory region was written message to reader-program!");
	memset(&startInfo, 0, sizeof(startInfo));
	startInfo.cb = sizeof(startInfo);
	if(!CreateProcess(NULL, comStr, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &startInfo, &procInfo))
	{
		showMessage(0,5, 124, "Error of creating process!");
		_getch();
		UnmapViewOfFile(baseAdress);
		toNormalState();
		return;
	}
	showMessage(0,8, 113, "Reader-programm was started!");	
	_getch();
	UnmapViewOfFile(baseAdress);
	toNormalState();
	return;
}
