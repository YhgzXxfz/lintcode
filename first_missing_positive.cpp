class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int len = A.size();
        
        for (int i = 0; i < len; ++i) {
            while (A[i] > 0 && A[i] <= len && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        
        for (int i = 0; i < len; ++i) {
            if (A[i] != i+1) return i+1;
        }
        return len +1;
    }
};

