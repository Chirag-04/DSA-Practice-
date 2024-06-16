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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh  = height(root->left);
        int rh  = height(root->right);
        return 1+max(lh , rh );
    }
    int maxi=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int left_h =  height(root->left);
        int right_h =  height(root->right);
        maxi = max(maxi , left_h +  right_h);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};