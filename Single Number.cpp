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
		if(nums.empty())
			return 0;
		int res=nums[0];
		for(int i=1;i<nums.size();i++)
			res^=nums[i];
		return res;
	}
};