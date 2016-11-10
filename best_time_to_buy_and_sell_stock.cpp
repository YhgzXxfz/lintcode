ass Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if (len < 1) return 0;
        
        int profit = 0;
        int minPrice = prices[0];
        for (int i = 0; i < len; ++i) {
            profit = max(profit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};


