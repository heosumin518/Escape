#pragma once
#include "main.h"
#include "util.h"

#ifndef KEY_CODE
#define KEY_CODE

// 키보드 값
#define UP     0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4 // 선택(스페이스바)

#endif

int keyControl();
void titleDraw();		// 타이틀 제목 출력
int menuDraw();		//메인 메뉴 출력
void infoDraw();