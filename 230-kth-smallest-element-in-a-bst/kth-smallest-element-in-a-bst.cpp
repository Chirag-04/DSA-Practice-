/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root , int k , int&ct  , int&ans){
        if(root==NULL) return;
        inorder(root->left , k , ct  ,ans);
        cout<<ct<<" "<<root->val<<endl;
        if(ct == k and ans==-1) ans = root->val;
        ct++;
        inorder(root->right,k , ct  ,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ct =1;
        int ans =-1;
        inorder(root , k , ct  ,ans);
        return ans ;
    }
};