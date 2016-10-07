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
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int height;
        return IsBalanced(root, height);
    }
    
    bool IsBalanced(TreeNode* root, int & height)
    {
        if (!root) {
            height = 0;
            return true;
        }
        
        int left_height, right_height;
        bool is_left_balanced = IsBalanced(root->left, left_height);
        bool is_right_balanced = IsBalanced(root->right, right_height);
        
        height = 1 + max(left_height, right_height);
        
        return is_left_balanced && is_right_balanced && 
            (abs(left_height-right_height) <= 1);
    }
};

