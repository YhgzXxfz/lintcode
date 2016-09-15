class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int len = A.size();
        for (int i = 0; i < len-1; ++i) {
            int min = A[i], min_index = i;
            for (int j = i+1; j < len; ++j) {
                if (A[j] < min) {
                    min = A[j];
                    min_index = j;
                }
            }
            swap(A[i], A[min_index]);
        }
    }
};
