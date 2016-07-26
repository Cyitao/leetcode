/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) 
	{
		vector<vector<int> > matrix(n,vector<int>(n,0));
		int val=1,start=0;
		while(2*start<n)
		{
			generateMatrixCore(matrix,val,start,n);
			start++;
		}
		return matrix;
	}
	void generateMatrixCore(vector<vector<int> > &matrix,int &val,int start,int n)
	{
		int end=n-start-1;
		for(int i=start;i<=end;i++)
			matrix[start][i]=val++;
		if(start<end)
		{
			for(int i=start+1;i<=end;i++)
				matrix[i][end]=val++;
		}
		if(start<end)
		{
			for(int i=end-1;i>=start;i--)
				matrix[end][i]=val++;
		}
		if(start<end-1)
		{
			for(int i=end-1;i>start;i--)
				matrix[i][start]=val++;
		}
		return;
	}
};