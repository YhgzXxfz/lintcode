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
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        if (!head || k == 1) return head;
        
        ListNode* preHead = new ListNode (-1);
        preHead->next = head;
        ListNode* prev = preHead, *curr = preHead, *next;
        
        int count = 0;
        while (curr) {
            ++count;
            curr = curr->next;
        }
        
        while (count >= k) {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            count -= k;
        }
        return preHead->next;
    }
};

