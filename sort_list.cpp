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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (!head || !head->next) return head;
        
        ListNode* slower = head, *faster = head->next->next;
        
        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
        }
        
        ListNode* pMiddle = sortList(slower->next);
        slower->next = NULL;
        
        return mergeList(sortList(head), pMiddle);
    }
    
    ListNode * mergeList(ListNode* h1, ListNode* h2) {
        ListNode node(0), *p = &node;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        
        if (h1) p->next = h1;
        if (h2) p->next = h2;
        
        return node.next;
    }
};




