/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	double myPow(double x, int n) 
	{
		if(n==0)
			return 1.0;
		double res=1.0;
		bool Is_Neg=false;
		if(n<0)
		{
			if(x>=1.0/INT_MAX||x<=1.0/INT_MIN)
				x=1.0/x;
			else
				return INT_MIN;
			if(n==INT_MIN)
			{
				res*=x;
				n++;
			}
		}
		n=abs(n);
		if(n%2==1&&x<0)
			Is_Neg=true;
		x=abs(x);
		while(n)
		{
			if(n&1==1)
			{
				if(res>INT_MAX/x)
					return INT_MAX;
				res*=x;
			}
			x*=x;
			n>>=1;
		}
		return Is_Neg?res*-1:res;
	}
};