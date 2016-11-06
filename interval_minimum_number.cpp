/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 
class SegmentTreeMinNode {
public :
    int start, end, min;
    SegmentTreeMinNode *left, *right;
    SegmentTreeMinNode(int start, int end, int min) {
        this->start = start;
        this->end = end;
        this->min = min;
        this->left = this->right = nullptr;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> result;
        int len = A.size();
        
        SegmentTreeMinNode * root = build(A, 0, len-1);

        for (auto& q : queries) {
            int minNumber = query(root, q.start, q.end);
            result.push_back(minNumber);
        }
        return result;
    }
    
private:
    SegmentTreeMinNode* build(vector<int> & A, int start, int end) {
        if (start > end) return nullptr;
        
        SegmentTreeMinNode* root = new SegmentTreeMinNode(start, end, INT_MAX);
        if (start == end) {
            root->min = A[start];
            return root;
        }
        
        root->left = build(A, start, (start+end)/2);
        root->right = build(A, (start+end)/2 +1, end);
        
        int left_min = root->left ? root->left->min : INT_MAX;
        int right_min = root->right ? root->right->min : INT_MAX;
        root->min = min(left_min, right_min);
        
        return root;
    }
    
    int query(SegmentTreeMinNode* root, int start, int end) {
        if (!root || start > end || root->start > end || root->end < start) return INT_MAX;
        
        if (start <= root->start && root->end <= end) return root->min;
        
        int left_min = query(root->left, start, end);
        int right_min = query(root->right, start, end);
        
        return min(left_min, right_min);
    }
};

