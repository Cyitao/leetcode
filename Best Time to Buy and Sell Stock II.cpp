/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int maxProfit(vector<int>& prices) 
	{
		if(prices.empty())
			return 0;
		int res=0;
		for(int i=1;i<prices.size();i++)
			if(prices[i]>prices[i-1])
				res+=prices[i]-prices[i-1];
		return res;
	}
};