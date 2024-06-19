/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
        TreeNode* f(vector<int>&nums , int s , int e){
        if(s > e) return NULL;
        // let create the root node 
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left_subtree =  f(nums , s , mid-1);
        TreeNode* right_subtree =  f(nums , mid+1 , e);
        // i will ask recursion to return 
        root->left = left_subtree;
        root->right = right_subtree;

        return root;
         

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int>nums;
        ListNode* temp = head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp= temp->next;
        } 
        for(auto it : nums) cout<<it<<" ";
        return f(nums , 0 , nums.size()-1);
    }
};