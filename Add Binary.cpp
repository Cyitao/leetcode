/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	string addBinary(string a, string b) 
	{
		if(b.empty())
			return a;
		if(a.empty())
			return b;
		int len=(a.length()>b.length())?a.length():b.length(),i,j,k;
		string res(len,'0');
		int carry=0;
		for(i=a.length()-1,j=b.length()-1,k=len-1;i>=0&&j>=0;i--,j--,k--)
		{
			int temp=(a[i]-'0')+(b[j]-'0')+carry;
			carry=temp/2;
			res[k]=temp%2+'0';
		}
		if(i>=0)
		{
			while(i>=0)
			{
				int temp=(a[i]-'0')+carry;
				carry=temp/2;
				res[i]=temp%2+'0';
				i--;
			}
		}
		if(j>=0)
		{
			while(j>=0)
			{
				int temp=(b[j]-'0')+carry;
				carry=temp/2;
				res[j]=temp%2+'0';
				j--;
			}
		}
		if(carry)
			res.insert(res.begin(),carry+'0');
		return res;
	}
};