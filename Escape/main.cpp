#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//Ű���� ��
#define UP	   0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// ����(�����̽� ��)

/* �Լ� ���� */
int keyControl();
void init();
void titleDraw();		// Ÿ��Ʋ ���� ���
int menuDraw();		//���� �޴� ���
void gotoxy(int, int);	//���콺 Ŀ���� �̵�

int main()
{
	init();
	titleDraw();
	int menuCode = menuDraw();
	printf("������ �޴�: %d\n", menuCode);
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

int menuDraw()
{
	int x = 24;
	int y = 12;		// -2�� �� ������ > �� ����ؾ��ϱ� ������
	gotoxy(x - 2, y);
	printf("> ���ӽ���");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("  ����  ");
	while (true)	// ���ѹݺ�	// Ű���� �Է��� ������ �ް� ��ٸ��� �ϴ� �κ�
	{
		int n = keyControl();	// Ű���� �̺�Ʈ�� Ű������ �޾ƿ��� // Ű������ Ű�ڵ带 �ӽ÷� �����ϴ� ����
		switch (n) {
			case UP: {
				if (y > 12) {	// y�� 12~14������ �̵�
					gotoxy(x - 2, y);	// ">"�� ��ĭ ������ ����ϱ� ���� x-2 �� ��
					printf(" ");		// ���� ��ġ�� ����
					gotoxy(x - 2, --y);	// ���� �̵��� ��ġ�� �̵��Ͽ�
					printf(">");		// �ٽ� �׸���
				}
				break;
			}
			case DOWN: {
				if (y < 14) {	// �ִ� 14
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 12;
				// y ���� ��ġ�� 12�����Ƿ� y-12�� �ϸ� 0, 1, 2 �� ���ڸ� �޾ƿ� �� �ִ�.
			}
		}
	}
}

int keyControl()
{
	char temp = _getch();	//���͸� �Է����� �ʾƵ� Ű�� ������ �ٷ� ��ȯ���ִ� �Է� �Լ�

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {		// �����̽���(����)�� ���� ��ư
		return SUBMIT;	
	}
}