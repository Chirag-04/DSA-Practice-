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
   // app 1 to store this in an array
   // app 2 to reverse the entire list and check whether it is equal to original list or not 
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL) return true;
    ///
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast and fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow ->pointing the middle elemnt of the list 
    ListNode* temp =  slow->next;
    slow->next = NULL;
    ListNode* np = reverseList(temp);
    slow->next = np;
    ListNode* i = head;
    ListNode* j = slow->next;
    while(j){
        if(i->val != j->val) return false;
        i= i->next ;
        j = j->next;
    }
    return true;
    }
};