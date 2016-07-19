/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	bool search(vector<int>& nums, int target) 
	{
		int low=0,high=nums.size()-1,mid;
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(nums[mid]==target)
				return true;
			if(nums[mid]>nums[low])//[low...mid]有序
			{
				if(nums[mid]>target&&nums[low]<=target)
					high=mid-1;
				else
					low=mid+1;
			}
			else if(nums[mid]<nums[low])//[mid...high]有序
			{
				if(nums[mid]<target&&nums[high]>=target)
					low=mid+1;
				else
					high=mid-1;
			}
			else
				low++;
		}
		return false;
	}
};