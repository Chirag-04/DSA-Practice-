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
    unordered_map<int,int>m; // all values are unique 
    bool find(TreeNode* root  , int k){
        if(root == NULL) return false;
        if(m.find(k-root->val) !=m.end()){
            return true;
        }else m[root->val]++;
        bool check1 = find(root->left , k);
        bool check2 = find(root->right , k);
        return (check1|check2);
    }
    bool findTarget(TreeNode* root, int k) {
        return find(root , k);
    }
};