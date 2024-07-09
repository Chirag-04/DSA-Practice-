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
    int length(ListNode* head){
        if(head == NULL) return 0;
        ListNode*temp = head;
        int len  = 0;
        while(temp){
            len++;
            temp= temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
     // we can use delay technique 
     if(head == NULL or head->next == NULL or k==0) return head;
     ListNode* slow =  head;
     ListNode* fast = head;
     int len  = length(head);
     int gap =  k%len;
     if(gap == 0) return head;
     while(gap--){
        fast= fast->next;
     } 
     while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
     }
     cout<<slow->val<<endl;
     cout<<fast->val<<endl;

     ListNode* nh= slow->next;
     slow->next = NULL;
     fast->next = head;
     return nh;
    }
};