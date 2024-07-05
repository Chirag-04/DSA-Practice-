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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        int prev = head->val;
        ListNode* temp =  head->next;
        int index = 1;
        while(temp and temp->next){
            if((temp->val > prev and temp->val > temp->next->val) or 
            (temp->val < prev and temp->val < temp->next->val) ){
                v.push_back(index);
            }
            index++;
            prev = temp->val;
            temp = temp->next;
        }
        if(v.size() < 2) return {-1 , -1};

        int mini = INT_MAX;
        for(int i=1 ; i<v.size() ; i++){
            mini = min(mini , v[i]-v[i-1]);
        }

        int maxi =  v[v.size()-1] -v[0];
        return {mini , maxi};
    }
};