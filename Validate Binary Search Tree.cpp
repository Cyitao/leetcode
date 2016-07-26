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
    bool isValidBST(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        stack<TreeNode*> sta;
        TreeNode *p=root;
        int lastval,order=0;
        while(!sta.empty()||p)
        {
            while(p)
            {
                sta.push(p);
                p=(*p).left;
            }
            p=sta.top();
            sta.pop();
            order++;
            if(order==1)
                lastval=(*p).val;
            else if(lastval>=(*p).val)
                return false;
            lastval=(*p).val;
            p=(*p).right;
        }
        return  true;
    }
};