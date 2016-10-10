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
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> result;
        searchRange(root, k1, k2, result);
        return result;
    }
    
    void searchRange(TreeNode* root, int k1, int k2, vector<int> & result) {
        if (!root) return;
        
        searchRange(root->left, k1, k2, result);
        if (root->val >= k1 && root->val <= k2) result.push_back(root->val);
        searchRange(root->right, k1, k2, result);
    }
};

