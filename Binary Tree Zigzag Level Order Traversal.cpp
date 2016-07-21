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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root==NULL)
             return res;
        stack<TreeNode*> sta1,sta2;//sta1偶数层存储，sta2奇数层存储
        sta1.push(root);
        vector<int> temp;
        while(!sta1.empty()||!sta2.empty())
        {
            while(!sta1.empty())
            {
                TreeNode *p=sta1.top();
                sta1.pop();
                temp.push_back((*p).val);
                if((*p).left)
                    sta2.push((*p).left);
                if((*p).right)
                    sta2.push((*p).right);
            }
            res.push_back(temp);
            temp.clear();
            while(!sta2.empty())
            {
                TreeNode *q=sta2.top();
                sta2.pop();
                temp.push_back((*q).val);
                if((*q).right)
                    sta1.push((*q).right);
                if((*q).left)
                    sta1.push((*q).left);
            }
            if(!temp.empty())
                res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};