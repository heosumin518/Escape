#include "util.h"


void init()
{
	system("mode con cols=56 lines=20 | title ��������");		// �ܼ�â ũ�� �ʱ�ȭ

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	// �ܼ� �ڵ� ��������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;		// false �Ǵ� 0 : �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}