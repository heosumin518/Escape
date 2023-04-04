#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//키보드 값
#define UP	   0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// 선택(스페이스 바)

/* 함수 선언 */
int keyControl();
void init();
void titleDraw();		// 타이틀 제목 출력
int menuDraw();		//메인 메뉴 출력
void gotoxy(int, int);	//마우스 커서를 이동

int main()
{
	init();
	titleDraw();
	int menuCode = menuDraw();
	printf("선택한 메뉴: %d\n", menuCode);
	return 0;
}

/* 함수 구현 */
void init()
{	
	system("mode con cols=56 lines=20 | title 게임제목");		// 콘솔창 크기 초기화
}

void titleDraw()
{
	printf("\n\n\n\n");	// 맨 위 4칸 개행
	printf("        #####    ##     ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);		// 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw()
{
	int x = 24;
	int y = 12;		// -2를 한 이유는 > 를 출력해야하기 때문에
	gotoxy(x - 2, y);
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");
	while (true)	// 무한반복	// 키보드 입력을 무한정 받고 기다리고 하는 부분
	{
		int n = keyControl();	// 키보드 이벤트를 키값으로 받아오기 // 키보드의 키코드를 임시로 저장하는 변수
		switch (n) {
			case UP: {
				if (y > 12) {	// y는 12~14까지만 이동
					gotoxy(x - 2, y);	// ">"를 두칸 이전에 출력하기 위해 x-2 를 함
					printf(" ");		// 원래 위치를 지움
					gotoxy(x - 2, --y);	// 새로 이동한 위치로 이동하여
					printf(">");		// 다시 그리기
				}
				break;
			}
			case DOWN: {
				if (y < 14) {	// 최대 14
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 12;
				// y 시작 위치가 12였으므로 y-12를 하면 0, 1, 2 세 숫자를 받아올 수 있다.
			}
		}
	}
}

int keyControl()
{
	char temp = _getch();	//엔터를 입력하지 않아도 키가 눌리면 바로 반환해주는 입력 함수

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
	else if (temp == ' ') {		// 스페이스바(공백)이 선택 버튼
		return SUBMIT;	
	}
}