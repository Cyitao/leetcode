/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int> >res;
		if(nums.size()<3)
			return res;
		sort(nums.begin(),nums.end());
		for(int i=nums.size()-1;i>=2;i--)
		{
			if(i<nums.size()-1&&nums[i]==nums[i+1])
				continue;
			vector<vector<int>>temp=threeSum(nums,0,i-1,0-nums[i]);
			if(!temp.empty())
			{
				for(int j=0;j<temp.size();j++)
				{
					vector<int> tt=temp[j];
					tt.push_back(nums[i]);
					res.push_back(tt);
				}
			}
		}
		return res;
	}
	vector<vector<int>> threeSum(vector<int>& nums,int start,int end,int target)
	{
		vector<vector<int>> res;
		vector<int> temp;
		while(start<end)
		{
			if(nums[start]+nums[end]==target)
			{
				temp.push_back(nums[start]);
				temp.push_back(nums[end]);
				res.push_back(temp);
				start++;
				end--;
				while(start<end&&nums[start]==nums[start-1])
					start++;
				while(start<end&&nums[end]==nums[end+1]) 
					end--;
				temp.clear();
			}
			else if(nums[start]+nums[end]>target)
				end--;
			else
				start++;
		}
		return res;
	}
};