/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
           return NULL;
        ListNode* p=head;
        int count=0;
        while(p)
        {
            p=(*p).next;
            count++;
        }
        return sortedListToBSTCore(head,0,count-1);
    }
    TreeNode* sortedListToBSTCore(ListNode *&p,int start,int end)
    {
        if(start>end)
             return NULL;
        int mid=start+(end-start)/2;
        TreeNode *left=sortedListToBSTCore(p,start,mid-1);
        TreeNode *root=new TreeNode((*p).val);
        (*root).left=left;
        p=(*p).next;
        TreeNode *right=sortedListToBSTCore(p,mid+1,end);
        (*root).right=right;
        return root;
    }
};