/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * };
 */
class Solution {
public:
 /**
 * @param head: The head of linked list.
 * @param m: The start position need to reverse.
 * @param n: The end position need to reverse.
 * @return: The new head of partial reversed linked list.
 */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if (m == n || !head || !head->next) return head;
     
        ListNode* curr = head, *next = head->next, *prev = head, *lastHead = head, *lastTail = head;
        int count = 1;
        while (count < m) {
            prev = curr;
            curr = next;
            next = next->next;
            ++count;
        }
        lastHead = prev;
        lastTail = curr;
            
        while (count < n) {
            prev = curr;
            curr = next;
            next = next->next;
                
            curr->next = prev;
                
            ++count;
        }
            
        if (m == 1) {
            head = curr;
        } else {
            lastHead->next = curr;
        }
        lastTail->next = next;
            
        return head;
    }
};


