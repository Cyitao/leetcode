/*/**
 * Author: ������
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) 
	{
		vector<vector<string>> res;
		if(n<=0)
			return res;
		vector<vector<int> > help=solveNQueensCore(n);
		for(int i=0;i<help.size();i++)
		{
			vector<string> temp;
			for(int j=0;j<n;j++)
			{
				string t(n,'.');
				t[help[i][j]]='Q';
				temp.push_back(t);
			}
			res.push_back(temp);
		}
		return res;
	}
	vector<vector<int> >solveNQueensCore(int n)
	{
		vector<vector<int> > res;
		vector<int> data(n,0);
		for(int i=0;i<n;i++)
			data[i]=i;
		vector<int> temp;
		vector<bool> flag(n,false);
		DFS(data,temp,flag,res);
		return res;
	}
	void DFS(vector<int> data,vector<int> temp,vector<bool> flag,vector<vector<int> > &res)
	{
		if(temp.size()==data.size())
		{
			res.push_back(temp);
			return;
		}
		for(int i=0;i<data.size();i++)
		{
			if(flag[i]==false)
			{
				if(temp.empty())
				{
					temp.push_back(data[i]);
					flag[i]=true;
					DFS(data,temp,flag,res);
					temp.pop_back();
				}
				else
				{
					bool f=true;
					for(int j=0;j<temp.size();j++)
					{
						int row=j,col=temp[j],next_row=temp.size();
						if(abs(col-data[i])==abs(row-next_row))
						{
							f=false;
							break;
						}
					}
					if(f)
					{
						temp.push_back(data[i]);
						flag[i]=true;
						DFS(data,temp,flag,res);
						temp.pop_back();
					}
				}
				flag[i]=false;
			}
		}
		return;
	}
};