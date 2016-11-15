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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if(!head || !head->next) return head;
        
        ListNode pseudoHead(0);
        pseudoHead.next = head;
        ListNode* prev1 = &pseudoHead, *prev2 = &pseudoHead;
        ListNode* curr1 = head, *curr2 = head;
        
        while (curr1) {
            if (curr1->val == v1) break;
            prev1 = curr1;
            curr1 = curr1->next;
        }
        if (!curr1) return head;
        
        while (curr2) {
            if (curr2->val == v2) break;
            prev2 = curr2;
            curr2 = curr2->next;
        }
        if (!curr2) return head;
        
        if (curr1->next == curr2) {
            prev1->next = curr2;
            curr1->next = curr2->next;
            curr2->next = curr1;
        } else if (curr2->next == curr1) {
            prev2->next = curr1;
            curr2->next = curr1->next;
            curr1->next = curr2;
        } else {
            ListNode* next2 = curr2->next;
            prev1->next = curr2;
            curr2->next = curr1->next;
            prev2->next = curr1;
            curr1->next = next2;
        }
        return pseudoHead.next;
    }
};
