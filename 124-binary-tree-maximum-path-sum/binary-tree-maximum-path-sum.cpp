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
    int ans  = INT_MIN ;
    int f(TreeNode* root){
        if(root == NULL) return 0;
        int left_max = f(root->left);
        int right_max= f(root->right);
        // ans updation 
        if(left_max < 0) left_max = 0;
        if(right_max < 0) right_max = 0;
        ans  =  max(ans , root->val + left_max + right_max);

        return max(root->val+ left_max , root->val + right_max);
    }
    int maxPathSum(TreeNode* root) {
        f(root);
       return ans ;
    }
};