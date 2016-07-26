/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/



class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) 
	{
		int hashtable[10]={0};
		for(int i=0;i<9;i++)
		{
			Init(hashtable);
			for(int j=0;j<9;j++)
				if(board[i][j]!='.')
				{
					hashtable[board[i][j]-'0']++;
					if(hashtable[board[i][j]-'0']>1)
						return false;
				}
		}
		for(int i=0;i<9;i++)
		{
			Init(hashtable);
			for(int j=0;j<9;j++)
				if(board[j][i]!='.')
				{
					hashtable[board[j][i]-'0']++;
					if(hashtable[board[j][i]-'0']>1)
						return false;
				}
		}
		for(int block=0;block<9;block++)
		{
			Init(hashtable);
			for(int i=block/3*3;i<block/3*3+3;i++)
				for(int j=block%3*3;j<block%3*3+3;j++)
					if(board[i][j]!='.')
					{
						hashtable[board[i][j]-'0']++;
						if(hashtable[board[i][j]-'0']>1)
							return false;
					}
		}
		return true;
	}
	void Init(int *hashtable)
	{
		for(int i=0;i<10;i++)
			hashtable[i]=0;
		return;
	}
};