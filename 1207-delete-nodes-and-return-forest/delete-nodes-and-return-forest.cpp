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
    vector<TreeNode*> ans ;
    unordered_map<int,int>m;
    void f(TreeNode* &root){
        if(root == NULL) return;
        f(root->left);
        f(root->right);

        if(m[root->val] ==1 ){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root = NULL;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& removed) {
        if(root == NULL) return {};
        for(auto it : removed){
            m[it]++;
        }
        f(root);
      
       if(root)ans.push_back(root);
  

        return ans ;
    }
};