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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        if (preorder.size() <= 0) return nullptr;
        return createTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* createTree(vector<int> & preorder, int preStart, int preEnd,
        vector<int> & inorder, int inStart, int inEnd)
    {
        if (preorder.empty() || preStart > preEnd || inStart > inEnd) return nullptr;
        
        TreeNode * root = new TreeNode (preorder[preStart]);
        int index;
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (inorder[i] == preorder[preStart])
            {
                index = i;
                break;
            }
        }
        
        root->left = createTree(preorder, preStart+1, preStart+index-inStart, 
            inorder, inStart, index-1);
        root->right = createTree(preorder, preStart+index-inStart+1, preEnd,
            inorder, index+1, inEnd);
            
        return root;
    }
};

