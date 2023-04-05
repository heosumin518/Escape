#include "game.h"


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

void titleDraw()
{
	printf("\n\n\n\n"); // 맨 위 4칸 개행  
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
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

void infoDraw()
{
	system("cls");	// 화면 모두 지우기
	printf("\n\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: W, A, S, D\n");
	printf("                    선택: 스페이스바\n\n\n\n\n\n\n");
	printf("               개발자: codevkr.tistory.com\n\n");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (true)
	{
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}