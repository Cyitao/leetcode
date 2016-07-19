/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		if(nums.empty())
			return 0;
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(nums[mid]==target)
				return mid;
			else if(nums[mid]>target)
				high=mid-1;
			else
				low=mid+1;
		}
		return low;
	}
};