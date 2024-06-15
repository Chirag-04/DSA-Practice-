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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p == NULL and q==NULL) return true;
      if(!p or !q) return false;
      bool check1 =  p->val ==  q->val;
    //   if(!check1) return false;
      bool check2 = isSameTree(p->left , q->left);
    //   if(!check2) return false;
       bool check3 = isSameTree(p->right , q->right);
    //   if(!check3) return false;

      return (check1 &  check2 & check3 );
    }
};