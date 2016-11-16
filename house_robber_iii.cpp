/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        return dfs(root).second;
    }
    
    pair<int, int> dfs(TreeNode * root) {
        if (!root) return {0,0};
        
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int f2 = l.second + r.second;
        int f1 = max(f2, l.first + r.first + root->val);
        return make_pair(f2, f1);
    }
};
