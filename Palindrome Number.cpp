/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	bool isPalindrome(int x) 
	{
		if(x==0||x==1)
			return true;
		if(x<0)
			return false;
		int div=1;
		while(div<=x/10)
			div*=10;
		while(x>0)
		{
			int high=x/div,low=x%10;
			if(high!=low)
				return false;
			x=(x%div)/10;
			div/=100;
		}
		return true;
	}
};