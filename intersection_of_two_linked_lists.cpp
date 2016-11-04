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
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if (!headA || !headB) return nullptr;
        
        ListNode* slower = headA, *faster = headA, *tail;
        while (slower->next) slower = slower->next;
        
        tail = slower;
        slower->next = headA;
        
        faster = headB; slower = headB;
        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
            if (slower == faster) break;
        }
        if (slower != faster) return nullptr;
        
        faster = headB;
        while (faster != slower) {
            faster = faster->next;
            slower = slower->next;
        }
        tail->next = nullptr;
        
        return slower;
    }
};

