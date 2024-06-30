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
    // inorer traversal in O(1)
    //using morris traversal
    // just check whether left node exist or not
    //
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* curr = root->left;
                while(curr->right!=NULL and curr->right!=root){
                    curr= curr->right;
                }
                // 
                if(curr->right == NULL){
                   curr->right = root;
                   root = root->left; 
                }
                else{
                    // left root traversed 
                    // now it's time to push the root nod e
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root= root->right;
                }
            }
        }

        return ans ;
    }
};