/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int>& nums) 
	{
		vector<vector<int> > res;
		vector<int> temp;
		res.push_back(temp);
		if(nums.empty())
			return res;
		sort(nums.begin(),nums.end());
		DFS(res,nums,temp,0);
		sort(res.begin(),res.end());
		vector<vector<int> >::iterator iter=unique(res.begin(),res.end());
		res.resize(distance(res.begin(),iter));
		return res;
	}
	void DFS(vector<vector<int> > &res,vector<int> nums,vector<int> temp,int index)
	{
		if(!temp.empty())
			res.push_back(temp);
		for(int i=index;i<nums.size();i++)
		{
			temp.push_back(nums[i]);
			DFS(res,nums,temp,i+1);
			temp.pop_back();
		}
		return;
	}
};