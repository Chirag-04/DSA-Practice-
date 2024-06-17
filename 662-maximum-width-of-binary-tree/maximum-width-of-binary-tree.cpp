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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode* ,int >>q;
        // pair of {node , index}
        // for idx i , lc : 2i+1  and rc :  2i+2;
        q.push({root , 0});
        int maxi = 0;
        while(!q.empty()){
            int lh = q.front().second;
            int rh = q.front().second;
            int sz = q.size();
            for(int i=0; i<sz ; i++){
                TreeNode* node = q.front().first;
                long long  index =  q.front().second;
                q.pop();
                rh = index;
                if(node->left) q.push({node->left , 2*index+1});
                if(node->right) q.push({node->right , 2*index+2});
            }
            maxi =max(maxi , rh-lh+1);
        }
        return maxi;
    }
};