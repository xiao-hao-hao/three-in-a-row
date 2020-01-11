#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//棋盘初始化函数 
{
	memset(board, ' ', row * col);
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	printf(" ");//为了行标号能对其打印
	for (i = 0; i < col; ++i)//打印列标号
	{
		printf(" %d  ", i + 1);
	}
	printf("\n");
	for (i = 0; i < row; ++i)
	{
		printf("%d", i + 1);//打印行标号
		for (j = 0; j < col; ++j)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			printf(" ");//为了将横线整体右移一个空格
			for (j = 0; j < col; ++j)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家走:\n");
	while (1)
	{
		printf("请玩家输入坐标:> ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = 'x';
				break;
			}
			else
			{
				printf("该位置已经有棋子了，请下其他位置！\n");
			}
		}
		else
		{
			printf("您选的位置不在棋盘上，请重新选位置！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走:>\n");
	while(1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'o';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)//返回0表示没满，返回1表示满了
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//char IsWin(char board[ROW][COL], int row, int col)//棋盘为3*3时对应的函数
//{
//	int i = 0;
//	for (i = 0; i < row; ++i)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
//		{
//			return board[i][0];
//		}
//	}
//	for (i = 0; i < col; ++i)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//		{
//			return board[0][i];
//		}
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
//	{
//		return board[0][0];
//	}
//	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')
//	{
//		return board[2][0];
//	}
//	if (IsFull(board, row, col) == 1)
//	{
//		return 'p';
//	}
//	return 'c';
//}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < row; ++i)//每一行连续的三个格的判断
	{
		for (j = 0; j < (col - 2); ++j)
		{
			if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < col; ++i)//每一列连续的三个格的判断
	{
		for (j = 0; j < (row - 2); ++j)
		{
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j][i] != ' ')
			{
				return board[j][i];
			}
		}
	}


	for (k = 0; k < col; ++k)//从左上到右下的上半三角的三点一线的判断
	{
		j = k;
		for (i = 0; ((i+2)<row) && ((j+2)<col); ++i, ++j)
		{
			if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	for (k = 0; k < row; ++k)//从左上到右下的下半三角的三点一线的判断
	{
		i = k;
		for (j = 0; ((i+2)<row) && ((j+2)<col); ++i, ++j)
		{
			if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	for (k = col; k > 0; --k)//从右上到左下的上半三角的三点一线的判断
	{
		j = k - 1;
		for (i = 0; ((i+2)<row) && ((j-2)>=0); ++i, --j)
		{
			if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	for (k = 0; k < row; ++k)//从右上到左下的下半三角的三点一线的判断
	{
		i = k;
		for (j = row - 1; ((i+2)<row) && ((j-2)>=0); ++i, --j)
		{
			if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	if (IsFull(board, row, col) == 1)
	{
		return 'p';
	}
	return 'c';
}
