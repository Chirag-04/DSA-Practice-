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
// we can calculate the node to root path 
// and we kow taht the first node will going to be uout target node 
// and we need to find the nodes preesnt at the k lvelve down 
    vector<TreeNode*>path;
    bool search(TreeNode*root ,TreeNode* target){
        if(root == NULL){
            return false;
        }

        if(root == target){
            path.push_back(root);
            return true;
        }

         bool check1 =  search(root->left  , target);
         if(check1){
            path.push_back(root);
            return true;
         }

         bool check2 = search(root->right , target);
         if(check2){
            path.push_back(root);
            return true;
         }

         return false;
    }
    vector<int>ans;
    void printKlevelDown(TreeNode* root , int k  , TreeNode*blocker){
        if(root== NULL or root == blocker) return  ;
        cout<<"val"<<root->val<<endl;
        if(k == 0){
            ans.push_back(root->val);
            return ;
        }
        printKlevelDown(root->left , k-1 , blocker);
        printKlevelDown(root->right , k-1 , blocker);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL) return  {};
        search(root , target );
        // for(auto it : path){
        //     cout<<it->val<<endl;
        // }
       cout<<path[0]->val<<endl;
       for(int i=0; i <path.size() ; i++){
        TreeNode* blocker  = NULL;
        if(i>=1) blocker = path[i-1];
          printKlevelDown(path[i] , k-i, blocker);
       }
        return ans;
    }
};