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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty())
            return NULL;
        return buildTreeCore(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* buildTreeCore(vector<int>& preorder,int prestart,int prend,vector<int>& inorder,int instart,int inend)
    {
        if(prestart>prend)
             return NULL;
        int key=preorder[prestart];
        TreeNode *root=new TreeNode(key);
        int pos=0;
        for(int i=instart;i<=inend;i++)
            if(inorder[i]==key)
            {
                pos=i;
                break;
            }
        int leftlen=pos-instart,rightlen=inend-pos;
        (*root).left=buildTreeCore(preorder,prestart+1,prestart+leftlen,inorder,instart,pos-1);
        (*root).right=buildTreeCore(preorder,prestart+leftlen+1,prend,inorder,pos+1,inend);
        return root;
    }
};