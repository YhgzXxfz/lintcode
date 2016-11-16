class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.empty()) return 0;
        
        int m = costs.size();
        vector<vector<int>> dp = costs;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        return min(dp[m-1][0], min(dp[m-1][1], dp[m-1][2]));
    }
};
