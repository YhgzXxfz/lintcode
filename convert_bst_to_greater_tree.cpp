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
     * @param root the root of binary tree
     * @return the new root
     */
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        
        int sum = 0;
        dfs(root, sum);
        return root;
    }

private:
    void dfs(TreeNode* root, int& sum) {
        if (!root) return ;
        
        dfs(root->right, sum);
        sum += root->val;
        root->val = sum;
        dfs(root->left, sum);
    }
};
