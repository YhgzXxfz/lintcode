class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int maxLR = 0, currLR = 0;
        int maxRL = 0, currRL = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            if (i == 0 || A[i] == A[i-1]) {
                ++currLR;
                maxLR = max(maxLR, currLR);
                ++currRL;
                maxRL = max(maxRL, currRL);
            } else if (A[i] > A[i-1]) {
                ++currLR;
                maxLR = max(maxLR, currLR);
                currRL = 1;
            } else if (A[i] < A[i-1]) {
                ++currRL;
                maxRL = max(maxRL, currRL);
                currLR = 1;
            }
        }
        return max(maxLR, maxRL);
    }
};

