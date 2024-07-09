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
// first of all we can use either slow or fasr to detec the cycle in the list
// or we can use map to store the nodes and detect the cycle in the list

    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , int >m;
        ListNode* temp = head;
        while(temp){
            if(m.find(temp)!=m.end()) return temp;
            m[temp]++;
            temp= temp->next;
        }
        return NULL;
    }
};