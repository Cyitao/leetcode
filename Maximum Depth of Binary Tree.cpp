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
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL)
             return 0;
        return max(maxDepth((*root).left),maxDepth((*root).right))+1;
    }
	//非递归
	int maxDepth(TreeNode* root) 
	{
		if(root==NULL)
			return 0;
		TreeNode *last=root,*nlast=NULL;//last当前层最右结点，nlast下层最右结点
		queue<TreeNode*> que;
		que.push(root);
		int level=0;
		while(!que.empty())
		{
			TreeNode *cur=que.front();
			que.pop();
			if((*cur).left)
			{
				que.push((*cur).left);
				nlast=(*cur).left;
			}
			if((*cur).right)
			{
				que.push((*cur).right);
				nlast=(*cur).right;
			}
			if(cur==last)
			{
				last=nlast;
				level+=1;
			}
		}
		return level;
	}
};