/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
//方法一：
class Solution {
public:
	string longestPalindrome(string s) 
	{
		string res;
		if(s.empty())
			return res;
		int n=s.length();
		for(int i=0;i<2*n-1;i++)
		{
			int left=i/2,right=i/2;
			if(i%2==1)
				right++;
			string temp=longestPalindromeCore(s,left,right);
			if(temp.length()>res.length())
				res=temp;
		}
		return res;
	}
	string longestPalindromeCore(string s,int left,int right)
	{
		while(left>=0&&right<s.length())
		{
			if(s[left]!=s[right])
				break;
			left--;
			right++;
		}
		left++;
		right--;
		return s.substr(left,right-left+1);
	}
};
//方法二：
class Solution {
public:
	string longestPalindrome(string s) 
	{
		string res;
		if(s.empty())
			return res;
		vector<vector<bool> > Is_Pali(s.length(),vector<bool>(s.length(),false));
		int max=0,pos=0;
		for(int i=s.length()-1;i>=0;i--)
			for(int j=i;j<s.length();j++)
				if(s[i]==s[j]&&(j-i<=2||Is_Pali[i+1][j-1]))
				{
					Is_Pali[i][j]=true;
					if(j-i+1>max)
					{
						max=j-i+1;
						pos=i;
					}
				}
				return s.substr(pos,max);
	}
};