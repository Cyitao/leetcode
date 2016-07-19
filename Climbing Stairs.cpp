/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int climbStairs(int n) 
	{
		if(n<=0)
			return 0;
		if(n<4)
			return n;
		int *dp=new int[n+1];
		dp[1]=1,dp[2]=2;
		for(int i=3;i<n+1;i++)
			dp[i]=dp[i-1]+dp[i-2];
		int res=dp[n];
		delete []dp;
		dp=NULL;
		return res;
	}
};