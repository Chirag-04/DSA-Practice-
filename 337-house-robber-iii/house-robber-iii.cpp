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
 struct hash_pair {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};
class Solution {
public:
    unordered_map<pair<TreeNode*, bool>, int, hash_pair> m;
    int f(TreeNode* root , bool isAdjacent){
        if(root == NULL) return 0;
        int pick = 0  , not_pick = 0 ;
        if(m.count({root , isAdjacent})) return m[{root , isAdjacent}];
        if(isAdjacent == 0){
            pick+=(root->val + f(root->left , 1)+f(root->right , 1)); 
        }
       not_pick += f(root->left , 0) + f(root->right , 0);
       return m[{root , isAdjacent}] = max(pick , not_pick);
    }
    int rob(TreeNode* root) {
        int ans = f(root , 0);
        return ans ;
    }
};

