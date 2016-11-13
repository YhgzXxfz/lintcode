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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (!head || !head->next) return head;
        
        int len = 1;
        ListNode* p = head;
        while (p->next) {
            ++len;
            p = p->next;
        }
        
        p->next = head;
        
        if (k %= len) {
            for (int i = 0; i < len-k; ++i) p = p->next;
        }
        
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

