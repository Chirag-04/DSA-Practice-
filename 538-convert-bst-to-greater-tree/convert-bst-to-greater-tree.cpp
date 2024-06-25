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
    int curr_sum = 0 ;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->right);
        curr_sum+=root->val;
        root->val = curr_sum;
        inorder(root->left);
        
    }
    TreeNode* convertBST(TreeNode* root) {
         inorder(root);
         return root;
    }
};