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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if (!root) return result;
        
        InorderTraversal(root, result);
        return result;
    }
    
    void InorderTraversal(TreeNode * root, vector<int> & result)
    {
        if (!root) return;
        
        InorderTraversal(root->left, result);
        result.push_back(root->val);
        InorderTraversal(root->right, result);
    }
};

