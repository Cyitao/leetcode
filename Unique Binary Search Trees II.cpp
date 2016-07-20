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
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode*> res;
        if(n<1)
             return res;
        res=gen(1,n);
        return res;
    }
    vector<TreeNode*> gen(int left,int right)
    {
        if(left>right)
        {
             vector<TreeNode*> res(1,NULL);
             return res;
        }
        vector<TreeNode*> res;     
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*> leftTree=gen(left,i-1);
            vector<TreeNode*> rightTree=gen(i+1,right);
            for(int j=0;j<leftTree.size();j++)
               for(int k=0;k<rightTree.size();k++)
               {
                   TreeNode* root=new TreeNode(i);
                  (*root).left=leftTree[j];
                  (*root).right=rightTree[k];
                  res.push_back(root);
               }
        }
        return res;
    }
};