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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        // 1
        //if (root == NULL) 
        //{
        //    root = node;
        //    return root;
        //}
        
        //if (node->val < root->val) 
        //{
        //    root->left = insertNode(root->left, node);
        //}
        //else
        //{
        //    root->right = insertNode(root->right, node);
        //}
        //return root;
        
        // 2
        if (!root) {
            root = node;
            return root;
        }
        
        TreeNode* father;
        TreeNode* son = root;
        while (son) {
            father = son;
            if (node->val < son->val) {
                son = son->left;
            } else {
                son = son->right;
            }
        }
        if (node->val < father->val) {
            father->left = node;
        } else {
            father->right = node;
        }
        return root;
    }
};

