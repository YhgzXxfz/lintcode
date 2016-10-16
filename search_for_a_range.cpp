class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        
        if (len <= 0) return vector<int> {-1, -1};
        
        vector<int> result;
        int left = 0, right = len-1, mid;
        while(left <= right) {
            mid = left + (right-left)/2;
            int midNumber = A[mid];
            if (target == midNumber) break;
            else if (target < midNumber) right = mid-1;
            else left = mid+1;
        }
        
        if (left > right) return vector<int> {-1, -1};
        
        for (int i = mid; i >= 0; --i) {
            if (A[i] < A[mid]) {
                left = i+1;
                break;
            }
            if (i == 0) left = 0;
        }
        
        for (int i = mid; i < len; ++i) {
            if (A[i] > A[mid]) {
                right = i-1;
                break;
            }
            if (i == len-1) right = len-1;
        }
        
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};

