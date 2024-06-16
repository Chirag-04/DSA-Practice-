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
    TreeNode* help(TreeNode* root){
        if(root == NULL) return root;
        TreeNode* left_ll = help(root->left);
        TreeNode* right_ll = help(root->right);
        TreeNode* temp = root;
       temp->left =NULL;
       temp->right = left_ll;
       while( temp and temp->right!=NULL){
        temp = temp->right;
       }
       temp->right = right_ll;
       return root;
    }
    void flatten(TreeNode* root) {
        root = help(root);
    }
};