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
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode* p1 = l1, *p2 = l2;
        ListNode * fakeHead = new ListNode(0), *head = fakeHead;
        
        int sum = 0;
        while (p1 != nullptr || p2 != nullptr) {
            sum /= 10;
            if (p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->val;
                p2 = p2->next;
            }
            
            ListNode* newNode = new ListNode(sum%10);
            head->next = newNode;
            head = head->next;
        }
        
        if (sum / 10 == 1) head->next = new ListNode(1);
        
        return fakeHead->next;
    }
};

