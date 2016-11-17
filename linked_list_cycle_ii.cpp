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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (!head || !head->next) return nullptr;
        
        ListNode* slower = head, *faster = head;
        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
            
            if (slower == faster) break;
        }
        if (!faster || !faster->next) return nullptr;
        
        faster = head;
        while (faster != slower) {
            slower = slower->next;
            faster = faster->next;
        }
        
        return faster;
    }
};




