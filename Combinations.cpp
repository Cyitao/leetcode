/*/**
 * Author: ≥£ﬁ»ÃŒ
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<int>> combine(int n, int k) 
	{
		vector<vector<int>> res;
		if(k<=0||n<k)
			return res;
		vector<int> temp;
		DFS(res,temp,n,k,1);
		return res;
	}
	void DFS(vector<vector<int> > &res,vector<int> temp,int n,int k,int index)
	{
		if(temp.size()==k)
		{
			res.push_back(temp);
			return;
		}
		for(int i=index;i<=n;i++)
		{
			temp.push_back(i);
			DFS(res,temp,n,k,i+1);
			temp.pop_back();
		}
		return;
	}
};