/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        if (!l1) return l2;
        if (!l2) return l1;
        
        unordered_map<int, int> mp1, mp2;
        int i = 1, j = 1;
        while (l1) {
            mp1[i++] = l1->val;
            l1 = l1->next;
        }
        while (l2) {
            mp2[j++] = l2->val;
            l2 = l2->next;
        }
        
        i--; j--;
        ListNode *head = nullptr;
        int carry = 0, a, b, sum;
        while (i > 0 || j > 0 || carry != 0) {
            a = i > 0 ? mp1[i] : 0;
            b = j > 0 ? mp2[j] : 0;
            sum = a+b+carry;
            
            auto node = new ListNode(sum%10);
            node->next = head;
            head = node;
            
            carry = sum/10;
            i--; j--;
        }
        return head;
    }
};



// 2
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
