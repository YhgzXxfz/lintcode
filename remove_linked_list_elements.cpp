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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode node(0); node.next = head;
        ListNode * prev = &node, *curr = head;
        
        while (curr != NULL)
        {
            while (curr != NULL && curr->val == val) curr = curr->next;
            prev->next = curr;
            if (curr != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return node.next;
    }
};

