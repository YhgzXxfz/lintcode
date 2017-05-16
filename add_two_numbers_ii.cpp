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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        return reverse(addTwoLists(reverse(l1), reverse(l2)));
    }
    
private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto next = head->next, rev = reverse(next);
        next->next = head;
        head->next = nullptr;
        return rev;
    }
    
    ListNode* addTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        int carry = 0;
        ListNode fakeHead(0), *curr = &fakeHead;
        while (l1 && l2) {
            int sum = l1->val+l2->val+carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            
            l1 = l1->next; l2 = l2->next;
        }
        
        while (l1) {
            int sum = l1->val+carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            
            l1 = l1->next;
        }
        
        while (l2) {
            int sum = l2->val+carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            carry = sum/10;
            
            l2 = l2->next;
        }
        
        if (carry) curr->next = new ListNode(carry);
        
        return fakeHead.next;
    }
};
