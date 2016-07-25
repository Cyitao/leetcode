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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root==NULL)
             return false;
        if((*root).left==NULL&&(*root).right==NULL&&(*root).val==sum)
             return true;
        return hasPathSum((*root).left,sum-(*root).val)||hasPathSum((*root).right,sum-(*root).val);
    }
};