#include "main.h"
#include "game.h"
#include "util.h"

//Ű���� ��
#define UP	   0
#define DOWN   1
#define LEFT   2
#define RIGHT  3
#define SUBMIT 4	// ����(�����̽� ��)

int main()
{
	init();
	while (true)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// ���ӽ���
		}
		else if (menuCode == 1) {
			infoDraw();	// ��������
		}
		else if (menuCode == 2) {
			return 0;	// ����
		}
		system("cls");		// �ܼ�â�� ������ Ŭ����. �ܼ� ��ǥ 0,0 ���� �ʱ�ȭ
	}
	
	return 0;
}