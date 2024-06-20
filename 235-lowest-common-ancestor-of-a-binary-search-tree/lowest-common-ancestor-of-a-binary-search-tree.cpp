/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// if it was a simple binary tree 
// the we could have done it using node to root path 
//in that we were first searhing our node 
// so if we againg search in bst that will take logn n time

class Solution {
public:
    // Function to find if a target is present and get the path
    bool isPresent(TreeNode* root, int target, vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            path.push_back(root);
            return true;
        }
        if (target > root->val) {
            bool check1 = isPresent(root->right, target, path);
            if (check1) {
                path.push_back(root);
                return true;
            }
        } else {
            bool check2 = isPresent(root->left, target, path);
            if (check2) {
                path.push_back(root);
                return true;
            }
        }
        return false;
    }

    // Function to find the lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        vector<TreeNode*> path1, path2;
        isPresent(root, p->val, path1);
        isPresent(root, q->val, path2);
        
        // Debug output to show paths
        // 
        
        for (auto it : path1) {
            cout << it->val << " ";
        }
        cout << endl;
        for (auto it : path2) {
            cout << it->val << " ";
        }
        cout << endl;
        
        TreeNode* lca = root;
        int i = path1.size() - 1, j = path2.size() - 1;
        while (i >= 0 && j >= 0) {
            if (path1[i]->val == path2[j]->val) {
                lca = path1[i];
            }
            i--, j--;
        }

        return lca;
    }
};