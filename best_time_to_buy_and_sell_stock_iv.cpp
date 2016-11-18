class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len/2) return quickSolve(prices);
        return dpSolve(prices, k);
    }
    
    int quickSolve(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;
        for (int i = 1; i < len; ++i) {
            profit += max(prices[i]-prices[i-1], 0);
        }
        return profit;
    }
    
    int dpSolve(vector<int>& prices, int k) {
        int len = prices.size();
        vector<int> balance(k+1, INT_MIN), profit(k+1);
        for (int i = 0; i < len; ++i) {
            for (int j = 1; j <= k; ++j) {
                balance[j] = max(balance[j], profit[j-1]-prices[i]);
                profit[j] = max(profit[j], balance[j]+prices[i]);
            }
        }
        return profit[k];
    }
};

