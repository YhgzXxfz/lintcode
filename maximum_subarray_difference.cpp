class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int len = nums.size();
        vector<int> maxLR(len), maxRL(len), minLR(len), minRL(len);
        
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
        
        int minSumLR = INT_MAX; sumLR = 0;
        for (int i = 0; i < len; ++i) {
            sumLR += nums[i];
            minSumLR = min(minSumLR, sumLR);
            minLR[i] = minSumLR;
            sumLR = min(sumLR, 0);
        }
        
        int minSumRL = INT_MAX; sumRL = 0;
        for (int i = len-1; i >= 0; --i) {
            sumRL += nums[i];
            minSumRL = min(minSumRL, sumRL);
            minRL[i] = minSumRL;
            sumRL = min(sumRL, 0);
        }
        
        int maxDiff = 0;
        for (int i = 0; i < len-1; ++i) {
            maxDiff = max(maxDiff, abs(maxLR[i] - minRL[i+1]));
            maxDiff = max(maxDiff, abs(minLR[i] - maxRL[i+1]));
        }
        
        return maxDiff;
    }
};


