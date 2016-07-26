/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/


class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		if(matrix.empty()||matrix[0].empty())
			return;
		int row=matrix.size(),col=matrix[0].size();
		int falgOffirstrow=1,falgOffirstcol=1;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(matrix[i][j]==0)
				{
					if(i>0)
						matrix[i][0]=0;
					else
						falgOffirstrow=0;
					if(j>0)
						matrix[0][j]=0;
					else
						falgOffirstcol=0;
				}
				for(int i=1;i<row;i++)
					if(matrix[i][0]==0)
					{
						for(int j=0;j<col;j++)
							matrix[i][j]=0;
					}
					for(int i=1;i<col;i++)
						if(matrix[0][i]==0)
						{
							for(int j=0;j<row;j++)
								matrix[j][i]=0;
						}
						if(falgOffirstrow==0)
						{
							for(int i=0;i<col;i++)
								matrix[0][i]=0;
						}
						if(falgOffirstcol==0)
						{
							for(int i=0;i<row;i++)
								matrix[i][0]=0;
						}
						return;
	}
};