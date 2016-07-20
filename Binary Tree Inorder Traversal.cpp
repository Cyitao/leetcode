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
    //非递归
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> sta;
        TreeNode *p=root;
        vector<int> res;
        while(p||!sta.empty())
        {
            while(p)
            {
                sta.push(p);
                p=(*p).left;
            }
            p=sta.top();
            res.push_back((*p).val);
            sta.pop();
            p=(*p).right;
        }
        return res;
    }
    /*//递归
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        InordeCore(root,res);
        return res;
    }
    void InordeCore(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
            return;
        InordeCore((*root).left,res);
        res.push_back((*root).val);
        InordeCore((*root).right,res);
        return;
    }*/
};