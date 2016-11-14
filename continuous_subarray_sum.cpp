class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        if (A.empty()) return {0, 0};
        
        int len = A.size();
        int first = 0, last = 0;
        int curr_sum = A[0], max_sum = curr_sum;
        
        for (int j = 0, i = 1; i < len; ++i) {
            if (curr_sum < 0) {
                j = i;
                curr_sum = 0;
            }
            
            curr_sum += A[i];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                first = j;
                last = i;
            }
        }
        return {first, last};
    }
};

