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
      priority_queue< pair<pair<int,int> ,int >  ,
         vector<pair<pair<int,int>,int  > > , 
        greater<pair<pair<int,int>,int  > >>pq;
        // for the same node 
    void f(int r  , int c , TreeNode* root){
        if(root==NULL) return ;
        pq.push({{c , r}  ,root->val});
        f(r+1 , c-1 , root->left);
        f(r+1 , c+1 , root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        f(0 ,0 ,  root );
        map<int , vector<int> >m;
        while(!pq.empty()){
            int col = pq.top().first.first;
            int val = pq.top().second;
            pq.pop();
            m[col].push_back(val);
        }
        vector<vector<int>>ans;
         for(auto it : m){
               ans.push_back(it.second);
           }
            return ans ;
    }
};