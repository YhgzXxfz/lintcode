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
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, target, path, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int gap, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;
        
        gap -= root->val;
        path.push_back(root->val);
        if (gap == 0 && !root->left && !root->right && !path.empty()) {
            result.push_back(path);
        }
        
        dfs(root->left, gap, path, result);
        dfs(root->right, gap, path, result);
        path.pop_back();
    }
};
