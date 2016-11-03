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
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        int len = lists.size();
        if (len == 0) return nullptr;
        
        ListNode* fakeHead = new ListNode(0), *head = fakeHead;
        
        priority_queue<ListNode*, vector<ListNode*> , cmp> queue;
        
        for (int i = 0; i < len; ++i) {
            if (lists[i]) queue.push(lists[i]);
        }
        
        while (!queue.empty()) {
            ListNode* node = queue.top();
            queue.pop();
            head->next = node;
            head = head->next;
            
            if (node->next) queue.push(node->next);
        }
        return fakeHead->next;
    }
    
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
};




