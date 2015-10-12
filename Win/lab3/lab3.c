#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <wincon.h>

void horLine(HANDLE display, short xBeg, short xEnd, short Y)
{
	int i = 0;
	DWORD len, actlen;
	COORD point;
	point.X = xBeg;
	point.Y = Y;
	SetConsoleCursorPosition(display, point);
	WriteFile(display, "*", 1, &actlen, NULL);
	for(i = xBeg+1; i < xEnd; i++)
	{
		WriteFile(display, "=", 1, &actlen, NULL);
	}
	WriteFile(display, "*", 1, &actlen, NULL);
}

void verLine(HANDLE display, short X, short yBeg, short yEnd)
{
	int i = 0;
	DWORD len, actlen;
	COORD point;
	point.X = X;
	point.Y = yBeg+1;
	for(i = yBeg; i < yEnd; i++)
	{
		SetConsoleCursorPosition(display, point);
		WriteFile(display, "|", 1, &actlen, NULL);
		point.Y ++;
	}
}

void rectangle(HANDLE display, short xBeg, short xEnd, short yBeg, short yEnd)
{
	horLine(display, xBeg, xEnd, yBeg);
	verLine(display, xBeg, yBeg, yEnd);
	verLine(display, xEnd, yBeg, yEnd);
	horLine(display, xBeg, xEnd, yEnd);
}

void errorMessege(HANDLE display)
{
	COORD point;
	DWORD actlen;
	char *text = "Error of creating handles!";
	point.X = 62;
	point.Y = 10;
	clrscr();
	SetConsoleTextAttribute(display, 4);
	rectangle(display, 50, 100, 5, 15);
	SetConsoleCursorPosition(display, point);
	WriteFile(display, text, 26, &actlen, NULL);
}

void lockMessege(HANDLE display)
{
	COORD point;
	DWORD actlen;
	char *text = "Lock installed successfully!";
	point.X = 61;
	point.Y = 10;
	clrscr();
	SetConsoleTextAttribute(display, 2);
	rectangle(display, 50, 100, 5, 15);
	SetConsoleCursorPosition(display, point);
	WriteFile(display, text, 28, &actlen, NULL);
}

void erLockMessege(HANDLE display)
{
	COORD point;
	DWORD actlen;
	char *text = "The file is already locked!";
	point.X = 61;
	point.Y = 10;
	clrscr();
	SetConsoleTextAttribute(display, 14);
	rectangle(display, 50, 100, 5, 15);
	SetConsoleCursorPosition(display, point);
	WriteFile(display, text, 28, &actlen, NULL);
}

int main()
{
	OVERLAPPED overlapped;
	COORD point;
	HANDLE fileHandle, displayHandle;
	DWORD len, actlen;
	char text[100];
	char name[] = "Z:/home/misha/Git/Cp/labs/os/Win/lab3/tolab3.txt";
	clrscr();
	overlapped.hEvent = 0;
	displayHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	fileHandle = CreateFile(name, GENERIC_READ, FILE_SHARE_READ,0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(fileHandle == INVALID_HANDLE_VALUE)
	{
		errorMessege(displayHandle);
		_getch();
		return 0;
	}
	if(!LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK | LOCKFILE_FAIL_IMMEDIATELY, NULL, 1, 0, &overlapped))
	{
		erLockMessege(displayHandle);
		LockFileEx(fileHandle, LOCKFILE_EXCLUSIVE_LOCK, NULL, 1, 0, &overlapped);
	}
	lockMessege(displayHandle);
	ReadFile(fileHandle, text, 100, &actlen, NULL);
	point.X = 25;
	point.Y = 18;
	SetConsoleCursorPosition(displayHandle, point);
	WriteFile(displayHandle, text, actlen, &actlen, NULL);
	_getch();
	UnlockFileEx(fileHandle, NULL, 1, 0, &overlapped);
	SetConsoleTextAttribute(displayHandle, 7);
	clrscr();
	return 0;

}
