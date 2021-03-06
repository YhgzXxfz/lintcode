/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (!head || !head->next) return head;
        
        ListNode* curr= head, *next = head->next, *prev;
        while (next) {
            prev = curr;
            curr = next;
            next = next->next;
            
            curr->next = prev;
            if (prev == head) prev->next = nullptr;
        }
        head = curr;
        return head;
    }
};


