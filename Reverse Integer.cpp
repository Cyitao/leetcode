/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int reverse(int x) 
	{
		if(x==INT_MIN)
			return 0;
		bool flag=false;
		if(x<0)
			flag=true;
		x=abs(x);
		int res=0;
		while(x)
		{
			if(res>(INT_MAX-(x%10))/10)//溢出的判断(不可以直接用x和INT_MAX比较)
				return 0;
			res=10*res+x%10;
			x=x/10;
		}
		if(flag)
			res*=-1;
		return res;
	}
};