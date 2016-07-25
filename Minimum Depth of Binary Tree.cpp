/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
             return 0;
        if((*root).left==NULL)
             return minDepth((*root).right)+1;
        else if((*root).right==NULL)
             return minDepth((*root).left)+1;
        else
             return min(minDepth((*root).left),minDepth((*root).right))+1;
    }
	//非递归
	int minDepth(TreeNode* root) 
	{
		if(root==NULL)
			return 0;
		queue<TreeNode*> que;
		que.push(root);
		TreeNode *last=root,*nlast=NULL;
		int level=1;
		while(!que.empty())
		{
			TreeNode *p=que.front();
			que.pop();
			if((*p).left==NULL&&(*p).right==NULL)
				break;
			if((*p).left)
			{
				que.push((*p).left);
				nlast=(*p).left;
			}
			if((*p).right)
			{
				que.push((*p).right);
				nlast=(*p).right;
			}
			if(last==p)
			{
				last=nlast;
				level++;
			}
		}
		return level;
	}
};