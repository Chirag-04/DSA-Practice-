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
// approach 1 is to use the inorder prop of the bst 
// apprah 2 is to use the hahsmap 
    bool f(TreeNode* root , int k , unordered_map<int,int>&m){
        if(root == NULL) return false;
        if(m.find(k- root->val) != m.end()){
            return true;
        }else m[root->val]++;
        bool check1 =  f(root->left , k , m);
        bool check2 =  f(root->right , k  , m);
        return check1|check2;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>m;
        return f(root , k , m);
    }
};