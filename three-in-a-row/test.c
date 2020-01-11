#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************************************\n");
	printf("*****            1.play            *****\n");
	printf("*****            2.exit            *****\n");	
	printf("****************************************\n");
}

void game()
{
	char board[ROW][COL] = {0};//创建一个棋盘
	srand((unsigned int)time(NULL));
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印初始键盘
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (IsWin(board , ROW, COL) == 'x')
		{
			printf("玩家胜！\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'o')
		{
			printf("电脑胜！\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'p')
		{
			printf("平局！\n");
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (IsWin(board , ROW, COL) == 'x')
		{
			printf("玩家胜！\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'o')
		{
			printf("电脑胜！\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'p')
		{
			printf("平局！\n");
			break;
		}
	}
}

void test()
{
	int i;
	do
	{
		menu();
		printf("请输入>>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择无效，请重新选择！\n");
			break;
		}
	} while (i);
}

int main()
{
	assert((ROW >= 3) && (COL >= 3));
	test();
	return 0;
}