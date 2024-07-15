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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*>m;
        for(auto it : des){
            int parent =it[0];
            int child = it[1];
            bool isleft = it[2];
            TreeNode* pnode  , *cnode;
            if(m.count(parent)) pnode = m[parent];
            else {
            pnode = new TreeNode(parent);
            m[parent] =  pnode;
            }

            if(m.count(child)) cnode = m[child];
            else {
            cnode = new TreeNode(child);
            m[child] = cnode;
            }

            if(isleft) pnode->left = cnode;
            else pnode->right = cnode; 
        }
        for(auto it : des){
            m[it[1]]= NULL;
        }
        TreeNode* root;
        for(auto it : m){
            if(it.second != NULL) root=it.second;
        }
        return root;
    }
};