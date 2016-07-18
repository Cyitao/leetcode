/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) 
	{
		if(board.empty()||board[0].empty())
			return false;
		if(word.empty())
			return true;
		bool res=false;
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[0].size();j++)
			{
				res=DFS(board,word,0,i,j);
				if(res)
					return res;
			}
			return res;
	}
	bool DFS(vector<vector<char> > &board,string word,int index,int row,int col)
	{
		if(index==word.length())
			return true;
		if(row<0||row>=board.size()||col<0||col>=board[0].size()||board[row][col]!=word[index])
			return false;
		bool res=false;
		int dirx[4]={0,0,-1,+1};//…œœ¬◊Û”“
		int diry[4]={+1,-1,0,0};
		for(int i=0;i<4;i++)
		{
			board[row][col]='0';
			res=res||DFS(board,word,index+1,row+dirx[i],col+diry[i]);
			if(res)
				return res;
			board[row][col]=word[index];
		}
		return res;
	}
};