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
	char *regName = "COMMON_MEMORY", *baseAdress, buffer[256];
	
	display = GetStdHandle(STD_OUTPUT_HANDLE);
	showMessage(80, 3, 122, "Program 2 messages:");
	memory_handle = OpenFileMapping(FILE_MAP_READ, FALSE, regName);
	if( memory_handle == NULL)
	{
		showMessage(80, 5, 124, "Error of opening common memory!");
		_getch();
		toNormalState();
		return;
	}
	showMessage(80, 5, 114, "Common memory region was opened!");
	baseAdress = MapViewOfFile(memory_handle, FILE_MAP_READ, 0,0,0);
	if(baseAdress == NULL)
	{
		showMessage(80, 5, 124, "Error of getting common memory!");
		_getch();
		toNormalState();
		return;	
	}
	showMessage(80, 6, 114, "Adress of beginning of common memory region was getting!");
	strncpy(buffer, baseAdress, 137);
	showMessage(80, 7, 114, "Message was readed from common memory region!");
	showMessage(0, 10, 122, "Message:");
	showMessage(10,10, 114, baseAdress);
//	printf("%s\n", buffer);
	

	
	_getch();
	UnmapViewOfFile(baseAdress);
	toNormalState();
	return;
}
