/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{//最大子序列
		if(nums.empty())
			return 0;
		int len=nums.size();
		int *dp=new int[len];
		dp[0]=nums[0];
		int res=dp[0];
		for(int i=1;i<len;i++)
		{
			if(dp[i-1]>0)
				dp[i]=dp[i-1]+nums[i];
			else
				dp[i]=nums[i];
			if(dp[i]>res)
				res=dp[i];
		}
		return res;
	}
};