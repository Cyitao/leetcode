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
    //非递归:使用一个栈
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root==NULL)
             return res;
        stack<TreeNode*> sta;
        TreeNode *h=root,*c=NULL;//h表示最近一次弹出打印的结点，c指向栈顶元素
        sta.push(root);
        while(!sta.empty())
        {
            c=sta.top();
            if((*c).left&&h!=(*c).left&&h!=(*c).right)
                sta.push((*c).left);
            else if((*c).right&&h!=(*c).right)
                sta.push((*c).right);
            else
            {
                res.push_back((*c).val);
                sta.pop();
                h=c;
            }
        }
        return res;
    }
    /*//非递归:使用两个栈
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root==NULL)
             return res;
        stack<TreeNode*> sta1,sta2;
        sta1.push(root);
        while(!sta1.empty())
        {
            TreeNode* p=sta1.top();
            sta2.push(p);
            sta1.pop();
            if((*p).left)
                sta1.push((*p).left);
            if((*p).right)
                sta1.push((*p).right);
        }
        while(!sta2.empty())
        {
            res.push_back((*sta2.top()).val);
            sta2.pop();
        }
        return res;
    }*/
    /*//递归
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        postorderCore(root,res);
        return res;
    }
    void postorderCore(TreeNode* root,vector<int> &res)
    {
        if(root==NULL)
             return;
        postorderCore((*root).left,res);
        postorderCore((*root).right,res);
        res.push_back((*root).val);
        return;
    }*/
};