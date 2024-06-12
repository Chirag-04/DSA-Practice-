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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans ;
        bool ltor = true;
        while(!q.empty()){
            int sz =  q.size();
            vector<int>temp(sz);
            for(int i=0 ; i<sz ; i++){
                TreeNode* node = q.front();
                int n = sz;
                q.pop();
                int index;
                index = i;
               if(ltor == false) index =  sz - i - 1;
                temp[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            ltor = !ltor;
        }
        return ans ;
    }
};