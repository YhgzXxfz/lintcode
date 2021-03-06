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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T1 == nullptr && T2 != nullptr) return false;
        if (IsSameTree(T1, T2)) return true;
        bool leftSub = isSubtree(T1->left, T2);
        bool rightSub = isSubtree(T1->right, T2);
        
        return leftSub || rightSub;
    }
    
    bool IsSameTree(TreeNode * T1, TreeNode * T2)
    {
        if (T1 == nullptr && T2 == nullptr) return true;
        if (T1 == nullptr || T2 == nullptr) return false;
        if (T1->val != T2->val) return false;
        
        bool leftSame = IsSameTree(T1->left, T2->left);
        bool rightSame = IsSameTree(T1->right, T2->right);
        
        return leftSame && rightSame;
    }
};

