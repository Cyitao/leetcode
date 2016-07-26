/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		vector<int> res;
		if(matrix.empty()||matrix[0].empty())
			return res;
		int row=matrix.size(),col=matrix[0].size();
		int start=0;
		while(2*start<row&&2*start<col)
		{
			PrintMatrix(matrix,res,start,row,col);
			start++;
		}
		return res;
	}
	void PrintMatrix(vector<vector<int>>& matrix,vector<int> &res,int start,int row,int col)
	{
		int endx=row-start-1,endy=col-start-1;
		for(int i=start;i<=endy;i++)
			res.push_back(matrix[start][i]);
		if(start<endx)
		{
			for(int i=start+1;i<=endx;i++)
				res.push_back(matrix[i][col-start-1]);
		}
		if(start<endy&&start<endx)
		{
			for(int i=endy-1;i>=start;i--)
				res.push_back(matrix[row-start-1][i]);
		}
		if(start<endx-1&&start<endy)
		{
			for(int i=endx-1;i>start;i--)
				res.push_back(matrix[i][start]);
		}
		return;
	}
};