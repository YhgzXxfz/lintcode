class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size(), min1, min2;
        vector<int> dp(k, 0);
        for (int i = 0; i < n; i++) {
            int premin1 = i ? min1 : 0, premin2 = i ? min2 : 0;
            min1 = min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[j] != premin1 || premin1 == premin2)
                    dp[j] = premin1 + costs[i][j];
                // pre_min1 occurred when painting house i-1 with color j, 
                // so it cannot be added to dp[j]
                else dp[j] = premin2 + costs[i][j];
                if (min1 <= dp[j]) min2 = min(min2, dp[j]);
                else min2 = min1, min1 = dp[j];
            }
        }
        return min1;
    }
};
