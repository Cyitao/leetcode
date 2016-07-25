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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        DFS(root,sum,res,temp);
        return res;
    }
    void DFS(TreeNode* root,int sum,vector<vector<int>> &res,vector<int> temp)
    {
        if(root==NULL)
            return;
        temp.push_back((*root).val);
        if((*root).left==NULL&&(*root).right==NULL)
        {
            if(sum==(*root).val)
                res.push_back(temp);
            return;
        }
        if((*root).left)
            DFS((*root).left,sum-(*root).val,res,temp);
        if((*root).right)
            DFS((*root).right,sum-(*root).val,res,temp);
        return;
    }
};