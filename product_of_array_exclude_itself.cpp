class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        long long prod = 1;
        int len = nums.size();
        vector<long long> result (len, 1);
        
        for (int i = 0; i < len; ++i) {
            prod = 1;
            for (int j = 0; j < len ; ++j) {
                if (j != i) prod *= nums[j];
            }
            result[i] = prod;
        }
        
        return result;
    }
};

