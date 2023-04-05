#include "main.h"
#include "game.h"
#include "util.h"

//키보드 값
#define UP	   0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// 선택(스페이스 바)

int main()
{
	init();
	while (true)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 게임시작
		}
		else if (menuCode == 1) {
			infoDraw();	// 게임정보
		}
		else if (menuCode == 2) {
			return 0;	// 종료
		}
		system("cls");		// 콘솔창의 모든글자 클리어. 콘솔 좌표 0,0 으로 초기화
	}
	
	return 0;
}