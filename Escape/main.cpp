#include <stdio.h>
#include <Windows.h>

/* �Լ� ���� */
void init();
void titleDraw();		// Ÿ��Ʋ ���� ���
void menuDraw();		//���� �޴� ���
void gotoxy(int, int);	//���콺 Ŀ���� �̵�

int main()
{
	init();
	titleDraw();
	menuDraw();
	return 0;
}

/* �Լ� ���� */
void init()
{	
	system("mode con cols=56 lines=20 | title ��������");		// �ܼ�â ũ�� �ʱ�ȭ
}

void titleDraw()
{
	printf("\n\n\n\n");	// �� �� 4ĭ ����
	printf("        #####    ##     ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// �ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void menuDraw()
{
	gotoxy(24 - 2, 12);
	printf("> ���ӽ���");
	gotoxy(24, 13);
	printf("��������");
	gotoxy(24, 14);
	printf("  ����  ");
}