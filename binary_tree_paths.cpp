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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> results;
        if (root == NULL) return results;
        
        string solution = "";
        BTPaths(root, results, solution);
        return results;
    }
    
    void BTPaths(TreeNode * root, vector<string> & results, string solution)
    {
        if (!root->left && !root->right) 
            results.push_back(solution + to_string(root->val));
        if (root->left)
            BTPaths(root->left, results, solution+to_string(root->val)+"->");
        if (root->right)
            BTPaths(root->right, results, solution+to_string(root->val)+"->");
    }
};

