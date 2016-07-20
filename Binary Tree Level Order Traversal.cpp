/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> >res;
        if(root==NULL)
             return res;
        queue<TreeNode*> que;
        vector<int> temp;
        TreeNode *last=root,*nlast=NULL;//nlast指向下一层最右结点，last当前打印行最右结点
        que.push(root);
        while(!que.empty())
        {
            TreeNode *p=que.front();
            que.pop();
            temp.push_back((*p).val);
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
            if(p==last)
            {
                res.push_back(temp);
                temp.clear();
                last=nlast;
            }
        }
        return res;
    }
};