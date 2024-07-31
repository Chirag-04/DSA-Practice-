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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val > key){
            root->left = deleteNode(root->left , key);
        }else if(root->val < key){
            root->right = deleteNode(root->right , key);
        }else{
            // now i will check number of children of it 
            // on the basis of that i will be able to return the node 
            if(root->left !=NULL and root->right!= NULL){
                TreeNode*temp = root->left;
                while(temp->right) temp= temp->right;
                root->val = temp->val;
                root->left =deleteNode(root->left , temp->val);
                return root;
            }else if(root->left){
                return root->left;
            }else if(root->right){
                return root->right;
            }else{
                return NULL;
            }
        }
        return root;
    }
};