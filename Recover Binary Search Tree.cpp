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
    void recoverTree(TreeNode* root) 
    {
        if(root==NULL)
            return;
        TreeNode *FirstMistake=NULL,*SecondMistake=NULL,*p=root,*pre=NULL;
        int NumofMistake=0,order=0,lastval;
        stack<TreeNode*> sta;
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
            {
                if(NumofMistake==0)
                {
                     FirstMistake=pre;
                     SecondMistake=p;
                }
                else
                {
                     SecondMistake=p;
                     break;
                }
                NumofMistake++;
            }
            lastval=(*p).val;
            pre=p;
            p=(*p).right;
        }
        int temp=(*FirstMistake).val;
        (*FirstMistake).val=(*SecondMistake).val;
        (*SecondMistake).val=temp;
        return;
    }
};