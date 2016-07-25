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
    bool isBalanced(TreeNode* root) 
    {
        int depth=0;
        return isBalancedCore(root,depth);
    }
    bool isBalancedCore(TreeNode* root,int &depth)
    {
        if(root==NULL)
        {
            depth=0;
            return true;
        }
        int depthleft=0,depthright=0;
        if(isBalancedCore((*root).left,depthleft)&&isBalancedCore((*root).right,depthright))
        {
            depth=max(depthleft,depthright)+1;
            if(abs(depthleft-depthright)<=1)
                 return true;
        }
        return false;
    }
};