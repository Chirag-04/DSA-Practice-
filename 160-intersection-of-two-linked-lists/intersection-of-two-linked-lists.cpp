/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*>v1;
        vector<ListNode*>v2;
        ListNode* temp1 = headA;
        while(temp1){
            v1.push_back(temp1);
            temp1= temp1->next;
        }
        ListNode* temp2 = headB;

        while(temp2){
            v2.push_back(temp2);
            temp2= temp2->next;
        }

        int i = v1.size()-1;
        int j = v2.size()-1;
       ListNode* dummy = new ListNode(-1);
        while(i>=0 and j>=0){
            if(v1[i] == v2[j]){
                dummy->next = v1[i];
                i--,j--;
            }
            else break;
        }
        return dummy->next;
    }
};