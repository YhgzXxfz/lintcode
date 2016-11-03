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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if (!head) return nullptr;
    
        ListNode *curr = head;
        ListNode *next = head;
        ListNode *prev = nullptr;
    
        while (next) {
            next = next->next;
    
            if (!next) break;
    
            next = next->next;
            prev = curr;
            curr = curr->next;
        }
    
        if (!curr) return new TreeNode(head->val);
        else {
            TreeNode * root = new TreeNode(curr->val);
            
            if (prev) {
                prev->next = nullptr;
                root->left = sortedListToBST(head);
            }
    
            root->right = sortedListToBST(curr->next);
    
            return root;
        }
    }
};




