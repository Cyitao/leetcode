/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
		vector<vector<int>> res;
		vector<int> temp;
		sort(candidates.begin(),candidates.end());
		vector<int>::iterator iter=unique(candidates.begin(),candidates.end());
		candidates.resize(distance(candidates.begin(),iter));
		Dfs(candidates,res,temp,target,0);
		sort(res.begin(),res.end());
		vector<vector<int>>::iterator iter1=unique(res.begin(),res.end());
		res.resize(distance(res.begin(),iter1));
		return res;
	}
	void Dfs(vector<int> candidates, vector<vector<int> > &res,vector<int> temp,int target,int index)
	{
		if(target<0)
			return;
		if(target==0)
		{
			res.push_back(temp);
			return;
		}
		for(int i=index;i<candidates.size();i++)
		{
			target-=candidates[i];
			temp.push_back(candidates[i]);
			if(target>=0)
				Dfs(candidates,res,temp,target,i);
			temp.pop_back();
			target+=candidates[i];
		}
		return;
	}
};