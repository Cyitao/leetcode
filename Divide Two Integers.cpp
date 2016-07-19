/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		if(divisor==0)
			return INT_MAX;
		if(dividend==0)
			return 0;
		bool Is_Neg=(((dividend^divisor)>>31)!=0);
		unsigned int res=0;
		if(dividend<0)
		{
			if(dividend==INT_MIN)
			{
				dividend+=abs(divisor);
				res++;
			}
			dividend*=-1;
		}
		if(divisor<0)
		{
			if(divisor==INT_MIN)
				return res;
			divisor*=-1;
		}
		while(dividend>=divisor)
		{
			unsigned int a=divisor,i;
			for(i=0;a<dividend;i++)
				if((a<<1)<=dividend)
					a<<=1;
				else
					break;
			dividend-=a;
			res+=(1<<i);
		}
		if(res==((unsigned int)INT_MAX+1)&&Is_Neg)
			return INT_MIN;
		if(res>((unsigned int)INT_MAX))
			return INT_MAX;
		if(Is_Neg)
		{
			int result=res;
			return result*-1;
		}
		return res;
	}
};