/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
// iterative
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        if (!root) return nullptr;
        
        stack<TreeNode*> s;
        s.push(root);
        DoublyListNode fakeHead(0), *prev = &fakeHead;
        auto node = root;
        
        while (!s.empty()) {
            while (node && node->left) {
                s.push(node->left);
                node = node->left;
            }
            
            node = s.top();
            s.pop();
            auto curr = new DoublyListNode(node->val);
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
            
            node = node->right;
            if (node) s.push(node);
        }
        return fakeHead.next;
    }
};



// recursive
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums);
        return convertSortedArrayToDoublyLinkedList(nums);
    }

private:
    void dfs(TreeNode* root, vector<int>& nums) {
        if (!root) return ;
        
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    
    DoublyListNode* convertSortedArrayToDoublyLinkedList(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return nullptr;
        
        auto head = new DoublyListNode(nums[0]), prev = head, curr = head;
        for (int i = 1; i < len; ++i) {
            curr = new DoublyListNode(nums[i]);
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
        return head;
    }
};



