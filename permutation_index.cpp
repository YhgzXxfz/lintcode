class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int len = A.size();
        
        if (len == 0) return 0;
        
        long long factor = 1, index = 1;
        for (int i = len-1; i >= 0; --i) {
            int rank = 0;
            for (int j = i+1; j < len; ++j) {
                if (A[i] > A[j]) ++rank;
            }
            index += rank*factor;
            factor *= (len - i);
        }
        return index;
    }
};

