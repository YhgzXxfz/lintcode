class Solution {
public:
    /**
     * @param nums a set of distinct positive integers
     * @return the largest subset 
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        
        sort(nums.begin(), nums.end());
        int len = nums.size(), largest_idx = 0;
        vector<int> dp(len, 1), prev(len, -1);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[largest_idx] < dp[i]) largest_idx = i;
        }
        
        vector<int> result;
        for (int i = largest_idx; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
        }
        reverse(nums.begin(), nums.end());
        return result;
    }
};
