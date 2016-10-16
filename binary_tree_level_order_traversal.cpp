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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        bfs(result, root, 1);
        return result;
    }
    
    void bfs(vector<vector<int>> & result, TreeNode* root, int level) {
        if (!root) return;
        
        if (level > result.size()) result.push_back(vector<int>());
        
        result[level-1].push_back(root->val);
        bfs(result, root->left, level+1);
        bfs(result, root->right, level+1);
    }
};


