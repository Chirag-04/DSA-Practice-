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
    int helper(TreeNode* root  , int& res){
        if(root == NULL) return 0;
        int lh = helper(root->left , res);
        int rh = helper(root->right , res);
        if(lh<0) lh =0;
        if(rh<0) rh = 0;
        int ans_to_be_returned =  root->val + max(lh , rh);
        res =  max(res , lh+rh+root->val);
        return ans_to_be_returned;
    }
    int maxPathSum(TreeNode* root) {
        int res =  INT_MIN;
        helper(root , res);  
        return res;
    }
};