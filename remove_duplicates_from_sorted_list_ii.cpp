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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (!head || !head->next) return head;
        
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* prev = fakeHead, *curr = head;
        
        while (curr) {
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return fakeHead->next;
    }
};

