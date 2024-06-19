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
    vector<int>inorder;
    void f(TreeNode* root ){
        if(root== NULL) return;
        f(root->left);
        inorder.push_back(root->val);
        f(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        f(root);
        return inorder[k-1];
    }
};