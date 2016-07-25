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
    int sumNumbers(TreeNode* root) 
    {
        int res=0,temp=0;
        DFS(root,temp,res);
        return res;
    }
    void DFS(TreeNode* root,int temp,int &res)
    {
        if(root==NULL)
            return;
        temp=temp*10+(*root).val;
        if((*root).left==NULL&&(*root).right==NULL)
        {
            res+=temp;
            return;
        }
        if((*root).left)
           DFS((*root).left,temp,res);
        if((*root).right)
           DFS((*root).right,temp,res);
        return;
    }
};