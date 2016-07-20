/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int maxProduct(vector<int>& nums) 
	{
		if(nums.empty())
			return 0;
		int local_min=nums[0],local_max=nums[0];
		int res=local_max;
		for(int i=1;i<nums.size();i++)
		{

			int temp=max(max(nums[i],nums[i]*local_min),nums[i]*local_max);
			local_min=min(min(nums[i],nums[i]*local_min),nums[i]*local_max);
			local_max=temp;
			res=max(local_max,res);
		}
		return res;
	}
};