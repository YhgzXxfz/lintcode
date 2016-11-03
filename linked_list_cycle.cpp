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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (!head || !head->next) return false;
        ListNode* slower = head, *faster = head;
        
        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
            if (slower == faster) return true;
        }
        return false;
    }
};




