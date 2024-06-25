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
    // approach 1 : O(n2) choosing a node and traversinig the entire tree to look for bigger values 
    // approach 2 : findinf the indorder traversal of the tree and then traverse on the tree and pdate the values
    int curr_sum = 0 ;
    int total = 0;
    void sum(TreeNode*root){
        if(root == NULL) return ;
        total+=root->val;
        sum(root->left);
        sum(root->right);
    }

    void inorder(TreeNode* root){
        if(root == NULL) return ;

        inorder(root->left);

        int old =  root->val;
        root->val =  (total-curr_sum);
        curr_sum+=old;
        cout<<root->val<<endl;

        inorder(root->right);

    }
    TreeNode* bstToGst(TreeNode* root) {
        sum(root);
        inorder(root);
        return root;
    }
};