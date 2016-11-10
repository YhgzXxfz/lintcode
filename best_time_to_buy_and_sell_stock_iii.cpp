class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if (len < 1) return 0;
        
        int valley = prices[0], peak = prices[len-1], maxProfit = 0;
        vector<int> f(len, 0);
        vector<int> g(len, 0);
        
        for (int i = 1 ; i < len; ++i) {
            valley = min(valley, prices[i]);
            f[i] = max(f[i-1], prices[i] - valley);
        }
        
        for (int i = len-2; i >= 0; --i) {
            peak = max(peak, prices[i]);
            g[i] = max(g[i+1], peak - prices[i]);
        }
        
        for (int i = 0 ;i < len ; ++i) {
            maxProfit = max(maxProfit, f[i]+g[i]);
        }
        return maxProfit;
    }
};

