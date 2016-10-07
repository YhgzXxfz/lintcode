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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode nodeL(0), nodeS(0);
        ListNode * pL = &nodeL, *pS = &nodeS;
        
        while (head) {
            if (head->val >= x) {
                pL->next = head;
                pL = pL->next;
            } else {
                pS->next = head;
                pS = pS->next;
            }
            head = head->next;
        }
        pL->next = nullptr;
        pS->next = nodeL.next;
        return nodeS.next;
    }
};




