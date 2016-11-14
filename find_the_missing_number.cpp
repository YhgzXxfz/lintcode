class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int length = nums.size();
        if (0 == length) return 0;
        
        int expected_sum = (0+length)*(1+length)/2;
        int actual_sum = 0;
        for (int i = 0; i < length; ++i) {
            actual_sum += nums[i];
        }
        return expected_sum - actual_sum;
    }
};

