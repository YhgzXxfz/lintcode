class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n < 2 || k == 0) return n*k;
        
        int s = k, dp1 = k, dp2 = k*(k-1);
        for (int i = 2; i < n; ++i)
        {
            s = dp2;
            dp2 = (k-1) * (dp1+dp2);
            dp1 = s;
        }
        return dp1+dp2;
    }
};
