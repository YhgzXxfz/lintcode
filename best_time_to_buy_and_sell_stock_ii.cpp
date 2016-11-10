class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int len = prices.size();
        if (len < 2) return 0;
        
        int sum = 0;
        for (int i = 1; i < len; ++i) {
            int diff = prices[i] - prices[i-1];
            sum += max(diff, 0);
        }
        return sum;
    }
};

