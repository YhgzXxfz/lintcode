class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<long long> dp(6*n+1), backup(6*n+1);
        for (int i = 1; i <= 6; ++i) dp[i] = 1;
        
        for (int i = 2; i <= n; ++i) {
            backup = dp;
            fill(dp.begin(), dp.end(), 0);
            for (int j = i; j <= 7*i/2; ++j) {
                for (int k = max(i-1, j-6); k < j; ++k) {
                    dp[j] += backup[k];
                }
                dp[7*i-j] = dp[j];
            }
        }
        
        long long denominator = pow(6, n);
        vector<pair<int, double>> result;
        for (int i = 1; i <= 6*n; ++i) {
            if (dp[i] != 0) {
                result.emplace_back(
                    make_pair((int)i, (double)dp[i]/(double)denominator)
                    );
            }
        }
        return result;
    }
};
