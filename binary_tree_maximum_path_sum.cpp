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
    int maxPathSum(TreeNode *root) {
        // write your code here
        if (!root) return 0;
        
        int max = INT_MIN;
        maxPathSum(root, max);
        return max;
    }
    
    int maxPathSum(TreeNode* root, int& result) {
        if (!root) return 0;
        int left = maxPathSum(root->left, result);
        int right = maxPathSum(root->right, result);
        
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;
        if (left + root->val + right > result) result = left+root->val+right;
        
        return root->val + max(left, right);
    }
};

