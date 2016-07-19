/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		if(matrix.empty()||matrix[0].empty())
			return false;
		int row=searchRow(matrix,target);
		if(row==-1)
			return false;
		int low=0,high=matrix[0].size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(matrix[row][mid]==target)
				return true;
			else if(matrix[row][mid]>target)
				high=mid-1;
			else
				low=mid+1;
		}
		return false;
	}
	int searchRow(vector<vector<int>>& matrix, int target)
	{
		int low=0,high=matrix.size()-1,mid;
		if(target<matrix[0][0]||matrix[high][matrix[0].size()-1]<target)
			return -1;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(matrix[mid][0]>target)
				high=mid-1;
			else
				low=mid+1;
		}
		return high;
	}
};