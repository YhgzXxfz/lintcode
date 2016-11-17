class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        vector<int> new_nums(len+2, 0);
        int n = 1;
        Initialize(new_nums, nums, n);
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n-k; ++left) {
                int right = left+k;
                for (int i = left+1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][i] + dp[i][right] + 
                        new_nums[left]*new_nums[i]*new_nums[right]);
                }
            }
        }
        return dp[0][n-1];
    }
    
    void Initialize(vector<int>& new_nums, vector<int>& nums, int& n) {
        for (auto num : nums) {
            if (num > 0) new_nums[n++] = num;
        }
        new_nums[0] = new_nums[n++] = 1;
    }
};

