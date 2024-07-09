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
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        if(!temp1) return temp2;
        if(!temp2) return temp1;
        ListNode* dummy  = new ListNode(-1);
        ListNode* head= dummy ;

        while(temp1!=NULL and temp2!=NULL){
            if(temp1->val < temp2->val){
                dummy->next = temp1;
                temp1= temp1->next;
                dummy = dummy->next;
            }else{
                dummy->next = temp2;
                temp2 = temp2->next;
                dummy = dummy->next;
            }
            if(temp1 == NULL and temp2){
                dummy->next= temp2;
            }
            if(temp2 == NULL and temp1){
                dummy->next = temp1;
            }
        }
        return head->next;
    }
};