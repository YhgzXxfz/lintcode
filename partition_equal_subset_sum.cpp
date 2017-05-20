class Solution {
public:
    /**
     * @param nums a non-empty array only positive integers
     * @return return true if can partition or false
     */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum>>1;
        if (sum &1) return false;
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (const auto& num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};
