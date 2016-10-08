class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int len = nums.size();
        int result = nums[0], sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            result = min(result, sum);
            sum = min(sum, 0);
        }
        return result;
    }
};


