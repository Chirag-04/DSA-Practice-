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
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>ans;
     stack<TreeNode*>s;
     TreeNode* node = root;
     while(true){
        if(node == NULL){
            if(s.empty()) break;
            TreeNode* ansNode = s.top();
            s.pop();
            ans.push_back(ansNode->val);
            node = ansNode->right;
        }
        else {
            s.push(node);
            node = node->left;
        }
     }

     return ans ;   
    }
};