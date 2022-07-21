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
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode;
        dummy->next = head;
        ListNode * prev = dummy;
        for(int i = 1 ; i < left ;i++){
            prev = prev->next;
        }
        ListNode * curr = prev->next;
        for(int i = 0 ; i < (right-left) ; i++){
            ListNode * aage = curr->next;
            curr->next = aage->next;
            aage->next = prev->next;
            prev->next = aage;
        }
        return dummy->next;
        
    }
};