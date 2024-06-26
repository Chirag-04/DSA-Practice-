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
    // brute force 
    vector<int>inorder; 
    void f(TreeNode* root){ 
        if(!root) return ;
        f(root->left);
        inorder.push_back(root->val);
        f(root->right);
    }
    TreeNode* constructTree( int s , int e){
        if(s > e) return NULL;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        TreeNode* lh = constructTree(s , mid-1);
        TreeNode* rh = constructTree(mid+1 , e);

        root->left =  lh;
        root->right =  rh;

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        f(root);
        // inorder will be ready 
        return constructTree(0 , inorder.size()-1);
    }
};