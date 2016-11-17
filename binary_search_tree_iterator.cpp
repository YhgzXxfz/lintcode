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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
private:
    stack<TreeNode*> height;
    
    void pushAllLeft(TreeNode* root) {
        while (root) {
            height.push(root);
            root = root->left;
        }
    }
    
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        // write your code here
        pushAllLeft(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !height.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* top = height.top();
        height.pop();
        if(top->right) pushAllLeft(top->right);
        
        return top;
    }
};

