#include <stdio.h>
#include <string.h>
#define N 10
void printMatrix(int board[N][N], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("\t");
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

}

int isSafe(int board[N][N], int x, int y, int n)
{
	int row, col;
	for (col = 0; col < y; col++)
	{
		if (board[x][col]) return 0;
	}

	for (row = x, col = y; row >= 0 && col >= 0; row--, col--)
	{
		if (board[row][col]) return 0;
	}

	for (row = x, col = y; row < n && col >= 0; row++, col--)
	{
		if (board[row][col]) return 0;
	}

	return 1;
}

int solveNQUtil(int board[N][N], int col, int n)
{
	if (col >= n) return 1; // all queens are placed then

	for (int row = 0; row < n; row++)
	{
		if (isSafe(board, row, col, n))
		{
			board[row][col] = 1;
			if (solveNQUtil(board, col + 1, n)) return 1;

			board[row][col] = 0; // Does not have a valid solution so backtracks
		}
	}

	return 0;
	
}

void solveNQ(int board[N][N], int n)
{
	if (solveNQUtil(board, 0, n))
	{
		printf("Solution not possible");	
	}

	printMatrix(board, n);
}

int main(void)
{
	int board[N][N];
	int n = N;

	memset(board, 0, sizeof(board));


	solveNQ(board, n);
}