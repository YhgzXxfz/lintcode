class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int len = nums.size();
        vector<int> maxLR(len), maxRL(len);
        
        int maxSumLR = INT_MIN, sumLR = 0;
        for (int i = 0; i < len; ++i) {
            sumLR += nums[i];
            maxSumLR = max(maxSumLR, sumLR);
            maxLR[i] = maxSumLR;
            sumLR = max(sumLR, 0);
        }
        
        int maxSumRL = INT_MIN, sumRL = 0;
        for (int i = len-1; i >= 0; --i) {
            sumRL += nums[i];
            maxSumRL = max(maxSumRL, sumRL);
            maxRL[i] = maxSumRL;
            sumRL = max(sumRL, 0);
        }
        
        int maxSum = INT_MIN;
        for (int i = 0; i < len-1; ++i) {
            maxSum = max(maxSum, maxLR[i]+maxRL[i+1]);
        }
        
        return maxSum;
    }
};


