/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	string multiply(string num1, string num2) 
	{
		string res;
		if(num1.empty()||num2.empty())
			return res;
		if(isZero(num1)||isZero(num2))
			return "0";
		int len1=num1.length(),len2=num2.length();
		int len=len1+len2-1;
		res.resize(len);
		int carry=0;
		for(int i=len-1,k=1;i>=0;i--,k++)
		{
			int temp=0;
			for(int j=1,h=k;h>0;j++,h--)
				if(j<=num1.length()&&h<=num2.length())
					temp+=(num1[len1-j]-'0')*(num2[len2-h]-'0');
			temp+=carry;
			carry=temp/10;
			res[i]=temp%10+'0';
		}
		if(carry)
			res.insert(res.begin(),carry+'0');
		return res;
	}
	bool isZero(string str)
	{
		return (str.size()==1&&str[0]=='0');
	}
};