/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		vector<vector<int> >res;
		if(nums.empty())
			return res;
		bool *used=new bool(nums.size());
		for(int i=0;i<nums.size();i++)
			used[i]=false;
		vector<int> temp;
		sort(nums.begin(),nums.end());
		DFS(nums,res,temp,used);
		delete []used;
		used=NULL;
		return res;
	}
	void DFS(vector<int>& nums,vector<vector<int> >&res,vector<int> temp,bool *used)
	{
		if(temp.size()==nums.size())
		{
			res.push_back(temp);
			return;
		}
		for(int i=0;i<nums.size();i++)
		{
			if(i>0&&!used[i-1]&&nums[i]==nums[i-1])
				continue;
			if(used[i]==false)
			{
				temp.push_back(nums[i]);
				used[i]=true;
				DFS(nums,res,temp,used);
				temp.pop_back();
				used[i]=false;
			}
		}
		return;
	}
};