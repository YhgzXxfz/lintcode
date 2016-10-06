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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        return convertSortedArrayToBST(A, 0, A.size()-1);
    }
    
    TreeNode * convertSortedArrayToBST(vector<int> & nums, int left, int right) {
        if (left > right) return NULL;
        
        int mid = (left+right) /2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* leftChild = convertSortedArrayToBST(nums, left, mid-1);
        TreeNode* rightChild = convertSortedArrayToBST(nums, mid+1, right);
        
        root->left = leftChild;
        root->right = rightChild;
        
        return root;
    }
};




