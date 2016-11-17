class SegmentTreeSumNode
{
public:
    int start, end;
    long long count;
    SegmentTreeSumNode* left, *right;
    SegmentTreeSumNode (int start, int end, long long count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /* you may need to use some attributes here */
    SegmentTreeSumNode* root;

    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        int len = A.size();
        root = build(A, 0, len-1);
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return queryTree(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        modifyTree(root, index, value);
    }
    
    SegmentTreeSumNode* build(vector<int>& A, int start, int end) {
        if (start > end) return nullptr;
        
        SegmentTreeSumNode* root = new SegmentTreeSumNode(start, end, 0);
        if (start == end) {
            root->count = A[start];
            return root;
        }
        
        root->left = build(A, start, (start+end)/2);
        root->right = build(A, (start+end)/2 +1, end);
        
        long long left_count = root->left ? root->left->count : 0;
        long long right_count = root->right ? root->right->count : 0;
        
        root->count = left_count + right_count;
        return root;
    }
    
    long long queryTree(SegmentTreeSumNode* root, int start, int end) {
        if (!root || start > end || root->start > end || root->end < start) return 0;
        
        if (start <= root->start && root->end <= end) return root->count;
        
        long long left_count = queryTree(root->left, start, end);
        long long right_count = queryTree(root->right, start, end);
        
        return left_count + right_count;
    }
    
    void modifyTree(SegmentTreeSumNode* root, int index, int value) {
        if (!root || index < root->start || index > root->end) return ;
        
        if (root->start == index && root->end == index) {
            root->count = value;
            return;
        }
        
        modifyTree(root->left, index, value);
        modifyTree(root->right, index, value);
        
        int left_count = root->left ? root->left->count : 0;
        int right_count = root->right ? root->right->count : 0;
        
        root->count = left_count + right_count;
    }
};


