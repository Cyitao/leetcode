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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL||q==NULL)
        {
            if(p==q)
                return true;
            return false;
        }
        if((*p).val!=(*q).val)
            return false;
        return isSameTree((*p).left, (*q).left)&&isSameTree((*p).right,(*q).right);
    }
};