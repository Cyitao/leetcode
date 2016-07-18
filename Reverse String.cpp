/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	string reverseString(string s)
	{
		int n=s.length(),begin,end;
		char temp;
		for(begin=0,end=n-1;begin<end;begin++,end--)
		{
			temp=s[begin];
			s[begin]=s[end];
			s[end]=temp;
		}
		return s;
	}
};