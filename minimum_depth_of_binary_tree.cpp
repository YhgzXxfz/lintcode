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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        
        int leftMinDepth = minDepth(root->left);
        int rightMinDepth = minDepth(root->right);
        
        if (leftMinDepth == 0 && rightMinDepth == 0)
        return 1;
        
        if (leftMinDepth == 0)
        return 1+rightMinDepth;
        
        if (rightMinDepth == 0)
        return 1+leftMinDepth;
        
        return 1+min(leftMinDepth, rightMinDepth);
    }
};

