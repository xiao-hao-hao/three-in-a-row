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
	char board[ROW][COL] = {0};//����һ������
	srand((unsigned int)time(NULL));
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ��ʼ����
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (IsWin(board , ROW, COL) == 'x')
		{
			printf("���ʤ��\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'o')
		{
			printf("����ʤ��\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'p')
		{
			printf("ƽ�֣�\n");
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (IsWin(board , ROW, COL) == 'x')
		{
			printf("���ʤ��\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'o')
		{
			printf("����ʤ��\n");
			break;
		}
		else if (IsWin(board, ROW, COL) == 'p')
		{
			printf("ƽ�֣�\n");
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
		printf("������>>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ����Ч��������ѡ��\n");
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