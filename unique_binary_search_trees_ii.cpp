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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode*> generateTrees(int n) {
        // write your code here
        if (n == 0) return generate (1, 0);
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int k = start; k <= end; ++k) {
            auto left = generate(start, k-1);
            auto right = generate(k+1, end);
            
            for (auto i : left) {
                for (auto j : right) {
                    TreeNode* node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

