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
// approach 1 : find out the lenght of the linked list 
// and tehn n-k th node and delete the next node 
// but 2 traversal will be there in that solution

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1 2 3 4 5
        //apparoach 2 delay technique 
        ListNode* slow = head;
        ListNode* fast = head ;  
        while(n--){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};