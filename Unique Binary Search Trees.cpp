/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution 
/*卡特兰数：
	Cn=C(n,2n)-C(n+1,2n)=(2n)!/(n!*(n+1)!);
	一般通项公式：
	Cn+1=Cn*(2*(2n+1))/(n+2)
	1,1,2,5,14...
*/
{
public:
	int numTrees(int n) 
	{
		int *dp=new int[n+1]();
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<n+1;i++)
			for(int j=0;j<i;j++)
				dp[i]+=dp[j]*dp[i-j-1];
		int res=dp[n];
		delete []dp;
		dp=NULL;
		return res;
	}
};