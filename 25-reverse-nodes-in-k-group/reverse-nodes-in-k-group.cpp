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
    ListNode* reverseList(ListNode* head) {
        // return recursive(head);
        if(head == NULL or head->next == NULL ) return head;
        ListNode* p =  NULL , *c = head   , *n = head->next;
        while(c){
            if(c) c->next = p;
            p = c;
            c = n;
            if(n) n = n->next;
        }
        return p;
    }
    ListNode* rev(ListNode* head , int k ){
        if(head== NULL or head->next == NULL or k == 1) return head;
        int i = 1 ;
        ListNode* slow = head , *fast = head;
        while( fast and i!=k){
            fast= fast->next;
            i++;
        }
        if(fast == NULL) return head;
        ListNode* recNode = fast->next;
        fast->next = NULL;
        ListNode* recList = rev(recNode , k);
        ListNode* nh =  reverseList(head);
        slow->next = recList;
        return nh;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return rev(head , k);
    }
};