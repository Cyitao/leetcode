/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.empty())
             return NULL;
        return helper(lists,0,lists.size()-1);
    }
    ListNode *helper(vector<ListNode*>& lists,int l,int h)
    {
        if(l<h)
        {
            int m=l+(h-l)/2;
            return mergeTwoLists(helper(lists,l,m),helper(lists,m+1,h));
        }
        return lists[l];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL||l2==NULL)
             return (l1==NULL)?l2:l1;
        if((*l1).val>(*l2).val)
             return mergeTwoLists(l2,l1); 
        ListNode  *head=l1,*pre=l1;
        while(l1&&l2)
        {
            if((*l1).val>(*l2).val)
            {
                ListNode  *temp=(*l2).next;
                (*l2).next=l1;
                (*pre).next=l2;
                pre=l2;
                l2=temp;
            }
            else
            {
                pre=l1;
                l1=(*l1).next;
            }
        }
        if(l1==NULL)
           (*pre).next=l2;
        return head;
    }
};