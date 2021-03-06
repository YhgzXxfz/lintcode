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
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if (a && !b) return false;
        if (!a && b) return false;
        if (!a && !b) return true;
        if (a->val != b->val) return false;
        
        bool isLeftSame = isIdentical(a->left, b->left);
        bool isRightSame = isIdentical(a->right, b->right);
        return isLeftSame && isRightSame;
    }
};
