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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if (!root) return true;
        if ((root->left) && (root->left->val > root->val)) return false;
        if ((root->right) && (root->right->val < root->val)) return false;
        
        vector<int> array = inorderToArray(root);
        return isAscendent(array);
    }
    
    vector<int> inorderToArray(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        InorderToArray(root, result);
        return result;
    }
    
    void InorderToArray(TreeNode* root, vector<int>& result) {
        if (!root) return;
        
        InorderToArray(root->left, result);
        result.push_back(root->val);
        InorderToArray(root->right, result);
    }
    
    bool isAscendent(vector<int> nums) {
        int len = nums.size();
        for (int i = 0; i < len-1; ++i) {
            if (nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
    
    
};

