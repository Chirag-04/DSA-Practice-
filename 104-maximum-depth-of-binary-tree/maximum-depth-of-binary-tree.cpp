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
// we know tht same pice of code can be used to solve the balanced tree prolem 
// at every node we are caalling recursion to cal andreturn me the left and right subtree height 

    int height(TreeNode* root){
        if(!root) return 0 ;
        int lh =   height(root->left);
        int rh  = height(root->right);
        return 1+max(lh , rh);
    }
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};