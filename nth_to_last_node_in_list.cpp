/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if (head == nullptr) return head;
        
        ListNode* pLeft = head, *pRight = head;
        int len = 0;
        while (pLeft != nullptr) {
            ++len;
            pLeft = pLeft->next;
        }
        if (len < n) return head;
        
        pLeft = head;
        for (int i = 0; i < n; ++i) {
            pLeft = pLeft->next;
        }
        
        while (pLeft != nullptr) {
            pLeft = pLeft->next;
            pRight = pRight->next;
        }
        return pRight;
        
    }
};




