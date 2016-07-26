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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.empty())
            return NULL;
        return buildTreeCore(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* buildTreeCore(vector<int>& inorder,int instart,int inend,vector<int>& postorder,int poststart,int postend)
    {
        if(instart>inend)
             return NULL;
        int key=postorder[postend],pos;
        TreeNode *root=new TreeNode(key);
        for(int i=instart;i<=inend;i++)
             if(inorder[i]==key)
             {
                 pos=i;
                 break;
             }
        int leftlen=pos-instart,rightlen=inend-pos;
        (*root).left=buildTreeCore(inorder,instart,pos-1,postorder,poststart,poststart+leftlen-1);
        (*root).right=buildTreeCore(inorder,pos+1,inend,postorder,poststart+leftlen,postend-1);
        return root;
    }
};