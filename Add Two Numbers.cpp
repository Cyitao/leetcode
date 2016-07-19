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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=(Length(l1)>Length(l2))?l1:l2;
        int carry=0;
        ListNode *p1=l1,*p2=l2,*t=head,*pre=head;
        while(p1&&p2)
        {
            int temp=(*p1).val+(*p2).val+carry;
            carry=temp/10;
            (*t).val=temp%10;
            pre=t;
            t=(*t).next;
            p1=(*p1).next;
            p2=(*p2).next;
        }
        if(p1)
        {
            while(p1)
            {
                int temp=(*p1).val+carry;
                carry=temp/10;
                (*t).val=temp%10;
                pre=t;
                t=(*t).next;
                p1=(*p1).next;
            }
        }
        if(p2)
        {
            while(p2)
            {
                int temp=(*p2).val+carry;
                carry=temp/10;
                (*t).val=temp%10;
                pre=t;
                t=(*t).next;
                p2=(*p2).next;
            }
        }
        if(carry)
            (*pre).next=new ListNode(1);
        return head;
    }
    int Length(ListNode *l)
    {
        int len=0;
        while(l)
        {
            len++;
            l=(*l).next;
        }
        return len;
    }
};