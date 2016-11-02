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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (!head || !head->next || !head->next->next) return;
        
        ListNode* slower = head, *faster = head;
        while (faster->next && faster->next->next) {
            slower = slower->next;
            faster = faster->next->next;
        }
        
        ListNode* preMiddle = slower, *curr = slower->next;
        while(curr->next) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = preMiddle->next;
            preMiddle->next = next;
        }
        
        ListNode* p1 = head, *p2 = preMiddle->next;
        while(p1 != preMiddle) {
            preMiddle->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMiddle->next;
        }
    }
};




