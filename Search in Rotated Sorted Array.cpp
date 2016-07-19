/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[mid]>=nums[low])//[low...mid]有序
			{
				if(nums[mid]>target&&nums[low]<=target)
					high=mid-1;
				else
					low=mid+1;
			}
			else//[mid...high]有序
			{
				if(nums[mid]<target&&nums[high]>=target)
					low=mid+1;
				else
					high=mid-1;
			}
		}
		return -1;
	}
};