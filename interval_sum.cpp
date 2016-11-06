/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 
class SegmentTreeSumNode {
public:
    int start, end;
    long long count;
    SegmentTreeSumNode * left, *right;
    SegmentTreeSumNode (int start, int end, long long count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = nullptr;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        int len = A.size();
        vector<long long> result;

        SegmentTreeSumNode* root = build(A, 0, len-1);

        for (auto q : queries) {
            long long sum = query(root, q.start, q.end);
            result.push_back(sum);
        }
        return result;
    }

private:    
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
    
    long long query(SegmentTreeSumNode* root, int start, int end) {
        if (!root || start > end || root->start > end || root->end < start) return 0;
        
        if (start <= root->start && root->end <= end) return root->count;
        
        long long left_count = query(root->left, start, end);
        long long right_count = query(root->right, start, end);
        
        return left_count + right_count;
    }
};

