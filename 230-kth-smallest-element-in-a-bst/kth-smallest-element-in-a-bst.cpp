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
    // method 1 :
    // method 2 : we can optimize the space here
    // since we do not need all the element 
    // vector<int>inorder;
    int ans  = -1; 
    int ct  = 1;
    void f(TreeNode* root , int k){
        if(root== NULL) return;
        f(root->left , k);
        // inorder.push_back(root->val);
        cout<<ct<<" "<<root->val<<endl;
        if(ct == k){
            ans = root->val;
             ct++;
            return;
        }
        ct++;
        f(root->right , k);
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root , k);
        return ans;
    }
};