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
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        return isSymmetricCore((*root).left,(*root).right);
    }
    bool isSymmetricCore(TreeNode *left,TreeNode *right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL||(*left).val!=(*right).val)
            return false;
        return isSymmetricCore((*left).left,(*right).right)&&isSymmetricCore((*left).right,(*right).left);
    }
};