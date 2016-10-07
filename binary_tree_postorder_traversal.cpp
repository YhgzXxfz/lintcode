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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if (!root) return result;
        
        PostorderTraversal(root, result);
        return result;
    }
    
    void PostorderTraversal(TreeNode * root, vector<int> & result)
    {
        if (!root) return;
        
        PostorderTraversal(root->left, result);
        PostorderTraversal(root->right, result);
        result.push_back(root->val);
    }
};

