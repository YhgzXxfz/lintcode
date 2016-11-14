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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (!head || !head->next) return true;
        
        ListNode* slower = head, *faster = head;
        while (faster->next && faster->next->next) {
            slower = slower->next;
            faster = faster->next->next;
        }
        
        slower->next = ReverseList(slower->next);
        slower = slower->next;
        faster = head;
        
        while (slower) {
            if (faster->val != slower->val) return false;
            faster = faster->next;
            slower = slower->next;
        }
        return true;
    }
    
    ListNode* ReverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *prev, *curr= head, *next = head->next;
        
        while (next) {
            prev = curr;
            curr = next;
            next = next->next;
            
            curr->next = prev;
            
            if (prev == head) prev->next = nullptr;
        }
        head = curr;
        return head;
    }
};

