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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode*head = dummy;
        ListNode* num1 = l1;
        ListNode* num2 = l2;
        int carry = 0 ;
        int sum= 0 ;
        while(num1 or num2){
            int a = 0 , b = 0;
            if(num1) a= num1->val;
            if(num2) b= num2->val;
            int sum =  a+ b+ carry;
            int last_digit = sum%10;
            carry =  sum/10;
            ListNode*new_node = new ListNode(last_digit);
            dummy->next = new_node;
            dummy = dummy->next;
            if(num1)num1= num1->next;
            if(num2)num2 =num2->next;
        }
        if(carry){
            ListNode* last = new ListNode(carry);
            dummy->next =  last;
        }
        return head->next;
    }
};