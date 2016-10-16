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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        bfs(result, root, 1, true);
        return result;
    }
    
    void bfs(vector<vector<int>> & result, TreeNode* root, int level, bool left_to_right) {
        if (!root) return;
        
        if (level > result.size()) result.push_back(vector<int>());
        
        if (left_to_right)
            result[level-1].push_back(root->val);
        else
            result[level-1].insert(result[level-1].begin(), root->val);
        
        bfs(result, root->left, level+1, !left_to_right);
        bfs(result, root->right, level+1, !left_to_right);
    }
};

