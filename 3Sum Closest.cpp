/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{//dif==sum-target
		if(nums.size()<3)
			return 0;
		sort(nums.begin(),nums.end());
		int sum=0,dif=INT_MAX;
		for(int i=nums.size()-1;i>=2;i--)
		{
			if(i<nums.size()-1&&nums[i]==nums[i+1])
				continue;
			int temp=towSumClosest(nums,0,i-1,target-nums[i]);
			if(abs(temp)<abs(dif))
			{
				dif=temp;
				sum=dif+target;
			}
		}
		return sum;
	}
	int towSumClosest(vector<int>& nums,int start,int end,int target)
		//返回绝对值最小的dif
	{
		int dif=INT_MAX;
		while(start<end)
		{
			if(nums[start]+nums[end]==target)
				return 0;
			else if(nums[start]+nums[end]>target)
			{
				if(abs(nums[start]+nums[end]-target)<abs(dif))
					dif=nums[start]+nums[end]-target;
				end--;
			}
			else
			{
				if(abs(nums[start]+nums[end]-target)<abs(dif))
					dif=nums[start]+nums[end]-target;
				start++;
			}
		}
		return dif;
	}
};