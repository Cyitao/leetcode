/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int n=matrix.size();
		int start=0;
		while(2*start<n)
		{
			int end=n-start-1;
			for(int i=start;i<end;i++)
			{
				int temp=matrix[start][i];
				matrix[start][i]=matrix[end-(i-start)][start];
				matrix[end-(i-start)][start]=matrix[end][end-(i-start)];
				matrix[end][end-(i-start)]=matrix[start+(i-start)][end];
				matrix[start+(i-start)][end]=temp;
			}
			start++;
		}
		return;
	}
};