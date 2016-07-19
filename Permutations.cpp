/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int> >res;
		if(nums.empty())
			return res;
		bool *flag=new bool(nums.size());
		for(int i=0;i<nums.size();i++)
			flag[i]=false;
		vector<int> temp;
		DFS(nums,res,temp,flag);
		delete []flag;
		flag=NULL;
		return res;

	}
	void DFS(vector<int>& nums,vector<vector<int> >&res,vector<int> temp,bool *flag)
	{
		if(temp.size()==nums.size())
		{
			res.push_back(temp);
			return;
		}
		for(int i=0;i<nums.size();i++)
		{
			if(flag[i]==false)
			{
				temp.push_back(nums[i]);
				flag[i]=true;
				DFS(nums,res,temp,flag);
				temp.pop_back();
				flag[i]=false;
			}
		}
		return;
	}
};