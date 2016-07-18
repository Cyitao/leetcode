/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int> >res;
		if(k<=0||k>=n)
			return res;
		vector<int> temp;
		DFS(res,temp,k,n,1);
		return res;
	}
	void DFS(vector<vector<int> >&res,vector<int> temp,int k,int target,int index)
	{
		if(target==0&&temp.size()==k)
		{
			res.push_back(temp);
			return;
		}
		if(target<0||temp.size()>k)
			return;
		for(int i=index;i<=9;i++)
		{
			target-=i;
			temp.push_back(i);
			DFS(res,temp,k,target,i+1);
			target+=i;
			temp.pop_back();
		}
		return;
	}
};