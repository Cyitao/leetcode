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
    int maxPathSum(TreeNode* root) 
    {
        int res=INT_MIN,help=INT_MIN;
        Post_Inorder(root,res,help);
        return res;
    }
    void Post_Inorder(TreeNode* root,int &res,int &help)
    {
        if(root==NULL)
        {
             help=0;
             return;
        }
        int helpleft=INT_MIN,helpright=INT_MIN;
        if((*root).left)
            Post_Inorder((*root).left,res,helpleft);
        if((*root).right)
            Post_Inorder((*root).right,res,helpright);
        int t=((helpleft>0)?helpleft:0)+((helpright>0)?helpright:0)+(*root).val;
        help=max(max(helpleft,helpright),0)+(*root).val;
        if(res<t)
            res=t;
        return;
    }
};