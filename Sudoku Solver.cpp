/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) 
	{
		if(board.empty()||board[0].empty()||board.size()!=9||board[0].size()!=9)
			return;
		DFS(board,0,0);
		return;
	}
	bool DFS(vector<vector<char>>& board,int i,int j)
	{
		if(j>=9)
			return DFS(board,i+1,0);
		if(i>=9)
			return true;
		if(board[i][j]=='.')
		{
			for(int k=1;k<=9;k++)
			{
				board[i][j]=k+'0';
				bool flag=isValid(board,i,j);
				if(flag)
				{
					if(DFS(board,i,j+1))
						return true;
				}
				board[i][j]='.';
			}
		}
		else
			return DFS(board,i,j+1);
		return false;
	}
	bool isValid(vector<vector<char>>& board,int x,int y)
	{
		bool res=false;
		int countx=0,county=0,count=0;
		for(int i=0;i<9;i++)
		{
			if(board[x][i]==board[x][y])
				countx++;
			if(board[i][y]==board[x][y])
				county++;
		}
		for(int i=x/3*3;i<x/3*3+3;i++)
			for(int j=y/3*3;j<y/3*3+3;j++)
				if(board[i][j]==board[x][y])
					count++;
		if(countx==1&&county==1&&count==1)
			res=true;
		return res;
	}
};