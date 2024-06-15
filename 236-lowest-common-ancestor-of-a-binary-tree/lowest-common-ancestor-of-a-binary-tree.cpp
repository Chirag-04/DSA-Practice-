/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // we have to find out the node to root path 
    // and wr know to find that we have to write the code 
    
    bool isPresent(TreeNode* root , int target , vector<TreeNode*>&path){
        if(root==NULL){
            return false;
        }
        if(root->val == target){
            path.push_back(root);
            return true;
        }

        bool check1 =  isPresent(root->left , target , path);
        if(check1 == true){
            path.push_back(root);
            return true;
        }

        bool check2 =  isPresent(root->right , target  , path);
        if(check2 == true){
            path.push_back(root);
            return true;
        }

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        vector<TreeNode*>path1 ,path2; 
        isPresent(root ,p->val ,  path1);
        isPresent(root ,q->val ,  path2);
        for(auto it: path1){
            cout<<it->val<<" ";
        }
        cout<<endl;
        for(auto it: path2){
            cout<<it->val<<" ";
        }
        TreeNode*lca  = root;
        int i=path1.size()-1 , j= path2.size()-1 ;
        while( i >=0 and j>=0){
            if(path1[i]->val == path2[j]->val){
                lca = path1[i];

            }
            i--,j--;
        }

        return lca;
    }
};