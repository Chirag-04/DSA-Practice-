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

// algo breakdown
// if left == null  print() and move to right 
// if left !=Null -> print()
// check if link is present or not 
// if no create a link and mvoe to left 

// if link is present move to right 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }
            else{
                
                TreeNode* curr = root->left;
                while(curr->right!=NULL and curr->right != root){
                    curr = curr->right;
                }
                if(curr->right == NULL){
                    ans.push_back(root->val);
                    curr->right = root;
                    root= root->left;
                }
                else{
                    curr->right = NULL;
                    root= root->right;
                }
            }
        }
        return ans;
    }
};