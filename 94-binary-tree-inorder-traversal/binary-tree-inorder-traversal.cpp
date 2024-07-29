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
    // inorer traversal in O(1)
    //using morris traversal
    // just check whether left node exist or not
    //
    vector<int>f(TreeNode* root){
        vector<int>ans;
        while(root){
            if(!root->left){
                // traverse the left subtree 
                ans.push_back(root->val);
                root= root->right;
            }else{
                // rooot's left exists 
                // now check whether there is a link or not 
                TreeNode* curr = root->left;
                while(curr->right and curr->right !=root){
                    curr = curr->right;
                }
                // if curr->right == NULL then create a thread
                if(curr->right == NULL){
                    curr->right = root;
                    root= root->left;
                }else{
                    // loop exist
                    // left side traversed 
                    ans.push_back(root->val);
                    curr->right = NULL;
                    root= root->right;
                }
            }
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {}; // return null;
        return f(root);
    //    vector<int>ans;  // 
        // while(root){
        //     // if teh root->left dos not exist 
        //     // we ahve completed the left subtree travers al
        //     // print the root 
        //     if(!root->left){
        //         ans.push_back(root->val); // into  my answer 
        //         root=root->right;
        //     }
        //     else{
        //         TreeNode* curr = root->left; // to check the thread 
        //         while(curr->right!=NULL and curr->right!=root){
        //             curr= curr->right;
        //         }
        //         // i need to check 
        //         // if curr ->right  = null then i need to create a thread 
        //         // but if not i need to break the thread adm move to the right 
        //         if(curr->right == NULL){ 
        //            curr->right = root;
        //            root = root->left; 
        //         }
        //         else{
        //             // left root traversed 
        //             // now it's time to push the root nod e
        //             // theere is a thread and left subtree has been traverse 
        //             // so break the thread and print ht root value 
        //             curr->right = NULL;
        //             ans.push_back(root->val);
        //             root= root->right;
        //         }
        //     }
        // }

        // return ans ;
    }
};