/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int numDecodings(string s) 
	{
		int n=s.length();
		if(n<=0||s[0]=='0')
			return 0;
		int *dp=new int[n+1];
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<n+1;i++)
		{
			if(s[i-2]=='0')
			{
				if(s[i-1]=='0')
					return 0;
				dp[i]=dp[i-2];
			}
			else if(s[i-1]=='0')
			{
				if(s[i-2]>'2')
					return 0;
				dp[i]=dp[i-2]; 
			}
			else if(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6'))
				dp[i]=dp[i-1]+dp[i-2];
			else
				dp[i]=dp[i-1];
		}
		int res=dp[n];
		delete []dp;
		dp=NULL;
		return res;
	}
};