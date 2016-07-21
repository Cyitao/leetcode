/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int>> res;
		if(nums.size()<4)
			return res;
		sort(nums.begin(),nums.end());
		for(int i=nums.size()-1;i>2;i--)
		{
			if(i<nums.size()-1&&nums[i]==nums[i+1])
				continue;
			vector<vector<int>> temp=threeSum(nums,0,i-1,target-nums[i]);
			for(int j=0;j<temp.size();j++)
			{
				temp[j].push_back(nums[i]);
				res.push_back(temp[j]);
			}
		}
		return res;
	}
	vector<vector<int>> threeSum(vector<int>& nums,int start,int end,int target)
	{
		vector<vector<int>> res;
		for(int i=end;i>=start+2;i--)
		{
			if(i<end&&nums[i]==nums[i+1])
				continue;
			vector<vector<int>> temp=twoSum(nums,start,i-1,target-nums[i]);
			for(int j=0;j<temp.size();j++)
			{
				temp[j].push_back(nums[i]);
				res.push_back(temp[j]);
			}
		}
		return res;
	}
	vector<vector<int>> twoSum(vector<int>& nums, int start,int end,int target)
	{
		vector<vector<int>>res;
		vector<int> temp;
		while(start<end)
		{
			if(nums[start]+nums[end]==target)
			{
				temp.push_back(nums[start]);
				temp.push_back(nums[end]);
				start++;
				end--;
				res.push_back(temp);
				temp.clear();
				while(start<end&&nums[start]==nums[start-1])
					start++;
				while(start<end&&nums[end]==nums[end+1])
					end--;
			}
			else if(nums[start]+nums[end]<target)
				start++;
			else
				end--;
		}
		return res;
	}
};