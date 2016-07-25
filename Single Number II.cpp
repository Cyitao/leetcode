/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int digits[32]={0};
		for(int i=0;i<32;i++)
		{
			for(int j=0;j<nums.size();j++)
				digits[i]+=(nums[j]>>i)&0x01;
		}
		int res=0;
		for(int i=0;i<32;i++)
			res+=(digits[i]%3)<<i;
		return res;
	}
};