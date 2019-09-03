#include <iostream>
#include <string.h>
using namespace std;
bool isSafe(int board[8][8],int i,int j)
{
	for(int row = 0;row < i;row++)
	{
		if(board[row][j] == 1)
			return false;
	}
	int x = i;
	int y = j;
	while(x >= 0 && y >= 0)
	{
		if(board[x][y] == 1)
			return false;
		x--;
		y--;
	}
	x = i;
	y = j;
	while(x >= 0 && y < 8)
	{
		if(board[x][y] == 1)
			return false;
		x--;
		y++;
	} 
	return true;
}
bool solveQueen(int board[][8],int i)
{
	if(i == 8)
	{
		for(int i = 0;i < 8;i++)
		{
			for(int j = 0;j < 8;j++)
			{
				if(board[i][j] == 1)
					cout << "Q ";
				else
					cout << "- ";
			}
			cout << endl;
		}
		cout << endl;
		return false;
	}
	for(int j = 0;j < 8;j++)
	{
		if(isSafe(board,i,j))
		{
			board[i][j] = 1;
			if(solveQueen(board,i+1))
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}
int main()
{
	int board[8][8];
	memset(board,0,sizeof(board));
	solveQueen(board,0);
	return 0;
}