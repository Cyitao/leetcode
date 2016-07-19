/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res(2,-1);
		if(nums.empty())
			return res;
		int left=SearchLeft(nums,target),right=SearchRight(nums,target);
		if(left<=right)
		{
			res[0]=left;
			res[1]=right;
		}
		return res;
	}
	int SearchLeft(vector<int>& nums, int target)
	{
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(nums[mid]<target)
				low=mid+1;
			else
				high=mid-1;
		}
		return low;
	}
	int SearchRight(vector<int>& nums, int target)
	{
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(nums[mid]>target)
				high=mid-1;
			else
				low=mid+1;
		}
		return high;
	}
};