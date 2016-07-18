/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		if(grid.empty()||grid[0].empty())
			return 0;
		int res=0;
		for(int i=0;i<grid.size();i++)
			for(int j=0;j<grid[0].size();j++)
				if(grid[i][j]=='1')
				{
					res++;
					DFS(grid,i,j);
				}
				return res;
	}
	void DFS(vector<vector<char> > &grid,int pos_x,int pos_y)
	{
		if(pos_x<0||pos_x>=grid.size()||pos_y<0||pos_y>=grid[0].size()||grid[pos_x][pos_y]=='0')
			return;
		int dirx[4]={0,0,-1,+1};//…œœ¬◊Û”“
		int diry[4]={+1,-1,0,0};
		grid[pos_x][pos_y]='0';
		for(int i=0;i<4;i++)
			DFS(grid,pos_x+dirx[i],pos_y+diry[i]);
		return;
	}
};