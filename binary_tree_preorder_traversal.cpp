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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if (!root) return result;
        
        PreorderTraversal(root, result);
        return result;
    }
    
    void PreorderTraversal(TreeNode* root, vector<int> & result)
    {
        if (!root) return;
        
        result.push_back(root->val);
        PreorderTraversal(root->left, result);
        PreorderTraversal(root->right, result);
    }
};


