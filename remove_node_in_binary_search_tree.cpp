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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (!root) return nullptr;
        if (root->val < value) root->right = removeNode(root->right, value);
        else if (root->val > value) root->left = removeNode(root->left, value);
        else {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            TreeNode* node = root;
            root = findMin(node->right);
            root->right = deleteMin(node->right);
            root->left = node->left;
        }
        return root;
    }
    
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    
    TreeNode* deleteMin(TreeNode* node) {
        if (!node->left) return node->right;
        
        TreeNode* root = node, *parent;
        while (node && node->left) {
            parent = node;
            node = node->left;
        }
        
        parent->left = node->right;
        
        return root;
    }
};

