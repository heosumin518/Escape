#include <stdio.h>
#include <Windows.h>

/* 함수 선언 */
void init();
void titleDraw();		// 타이틀 제목 출력
void menuDraw();		//메인 메뉴 출력
void gotoxy(int, int);	//마우스 커서를 이동

int main()
{
	init();
	titleDraw();
	menuDraw();
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

void menuDraw()
{
	gotoxy(24 - 2, 12);
	printf("> 게임시작");
	gotoxy(24, 13);
	printf("게임정보");
	gotoxy(24, 14);
	printf("  종료  ");
}