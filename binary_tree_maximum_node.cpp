class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        TreeNode* max_node = root;
        int max_value = INT_MIN;
        dfs(root, max_value, max_node);
        return max_node;
    }

private:
    void dfs(TreeNode* root, int& max_value, TreeNode*& max_node) {
        if (!root) return ;
        
        if (root->val > max_value) {
            max_value = root->val;
            max_node = root;
        }
        dfs(root->left, max_value, max_node);
        dfs(root->right, max_value, max_node);
    }
};
