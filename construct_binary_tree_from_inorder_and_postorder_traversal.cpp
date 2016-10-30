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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
     int pIO;
     int pPO;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        pIO = inorder.size()-1;
        pPO = postorder.size()-1;
        return buildTree(inorder, postorder, nullptr);
    }
    
    TreeNode * buildTree(vector<int> & inorder, vector<int> & postorder, TreeNode * end)
    {
        if (pPO < 0) return nullptr;
        
        TreeNode * node = new TreeNode(postorder[pPO]);
        --pPO;
        
        if (inorder[pIO] != node->val) node->right = buildTree(inorder, postorder, node);
        
        --pIO;
        
        if ((end == nullptr) || (inorder[pIO] != end->val)) 
            node->left = buildTree(inorder, postorder, end);
        
        return node;
    }
};

