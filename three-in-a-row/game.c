#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//���̳�ʼ������ 
{
	memset(board, ' ', row * col);
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	printf(" ");//Ϊ���б���ܶ����ӡ
	for (i = 0; i < col; ++i)//��ӡ�б��
	{
		printf(" %d  ", i + 1);
	}
	printf("\n");
	for (i = 0; i < row; ++i)
	{
		printf("%d", i + 1);//��ӡ�б��
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
			printf(" ");//Ϊ�˽�������������һ���ո�
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
	printf("�����:\n");
	while (1)
	{
		printf("�������������:> ");
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
				printf("��λ���Ѿ��������ˣ���������λ�ã�\n");
			}
		}
		else
		{
			printf("��ѡ��λ�ò��������ϣ�������ѡλ�ã�\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������:>\n");
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

int IsFull(char board[ROW][COL], int row, int col)//����0��ʾû��������1��ʾ����
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

//char IsWin(char board[ROW][COL], int row, int col)//����Ϊ3*3ʱ��Ӧ�ĺ���
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
	for (i = 0; i < row; ++i)//ÿһ����������������ж�
	{
		for (j = 0; j < (col - 2); ++j)
		{
			if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < col; ++i)//ÿһ����������������ж�
	{
		for (j = 0; j < (row - 2); ++j)
		{
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j][i] != ' ')
			{
				return board[j][i];
			}
		}
	}


	for (k = 0; k < col; ++k)//�����ϵ����µ��ϰ����ǵ�����һ�ߵ��ж�
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

	for (k = 0; k < row; ++k)//�����ϵ����µ��°����ǵ�����һ�ߵ��ж�
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

	for (k = col; k > 0; --k)//�����ϵ����µ��ϰ����ǵ�����һ�ߵ��ж�
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

	for (k = 0; k < row; ++k)//�����ϵ����µ��°����ǵ�����һ�ߵ��ж�
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
