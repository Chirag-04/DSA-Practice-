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
    ListNode* recursive(ListNode* head){
        if(head == NULL or head->next == NULL) return head;
        ListNode*oh = head;
        ListNode*nh = head->next;
        oh->next = NULL;
        ListNode* finalhead = recursive(nh);
        ListNode* temp = finalhead;
        while(temp and temp->next) temp = temp->next;
        if(temp) temp->next =  oh; 
        oh->next = NULL;
        return finalhead;
    }
    ListNode* reverseList(ListNode* head) {
        return recursive(head);
    }
};