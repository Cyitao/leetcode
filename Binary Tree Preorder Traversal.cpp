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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
            TreeNode *p=sta.top();
            sta.pop();
            res.push_back((*p).val);
            if((*p).right)
                sta.push((*p).right);
            if((*p).left)
                sta.push((*p).left);
        }
        return res;
    }
    /*//递归
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        preorderCore(root,res);
        return res;
    }
    void preorderCore(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
            return;
        res.push_back((*root).val);
        preorderCore((*root).left,res);
        preorderCore((*root).right,res);
        return;
    }*/
};