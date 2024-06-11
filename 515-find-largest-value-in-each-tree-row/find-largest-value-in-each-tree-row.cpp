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
    vector<int>ans;
    void f(TreeNode* root , int level){
        if(root == NULL) return ;
        // when th level coming for the first time 
        if(ans.size() == level){
            ans.push_back(root->val);
        }else{
            ans[level] = max(ans[level] , root->val);
        }
        f(root->left , level+1);
        f(root->right ,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        f(root , 0);
        return ans ;
    }
};