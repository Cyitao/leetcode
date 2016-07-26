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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.empty())
            return NULL;
        return sortedArrayToBSTCore(nums,0,nums.size()-1);
    }
    TreeNode *sortedArrayToBSTCore(vector<int>& nums,int start,int end)
    {
        if(start>end)
              return NULL;
        else
        {
            int mid=start+(end-start)/2;
            TreeNode *p=new TreeNode(nums[mid]);
            (*p).left=sortedArrayToBSTCore(nums,start,mid-1);
            (*p).right=sortedArrayToBSTCore(nums,mid+1,end);
            return p;
        }
    }
};