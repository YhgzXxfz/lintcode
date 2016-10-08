class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int len = nums.size();
        
        int result = nums[0], sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            result = max(result, sum);
            sum = max(sum, 0);
        }
        return result;
    }
};


