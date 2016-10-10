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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        string result;
        serialize(root, &result);
        return result;
    }
    
    void serialize(TreeNode * root, string * result) {
        if (!root) result->append("# ");
        else {
            result->append(to_string(root->val).append(" "));
            serialize(root->left, result);
            serialize(root->right, result);
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
        int start = 0;
        return deserialize(data, start);
    }
    
    TreeNode* deserialize(string data, int& start) {
        int num;
        if (! getNumber(data, start, num)) return nullptr;
        else {
            TreeNode* root = new TreeNode(num);
            root->left = deserialize(data, start);
            root->right = deserialize(data, start);
            return root;
        }
    }
    
    bool getNumber(string data, int& start, int& num) {
        int sign = 1;
        if (data[start] == '#') {
            start += 2;  // Skip "# ".
            return false;
        } else if (data[start] == '-') {
            sign = -1;
            ++start;
        }

        for (num = 0; isdigit(data[start]); ++start) {
            num = num * 10 + data[start] - '0';
        }
        num *= sign;
        ++start;  // Skip " ".

        return true;
    }
};


