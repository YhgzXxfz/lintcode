class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int length = values.size();
        
        if (length <= 2) return true;
        vector<int> f(length, 0);
        
        // f(i) means the max profit (min loss) begin from i to end for both players
        f[length-1] = values[length-1];
        f[length-2] = values[length-2];
        
        for (int i = length-3; i >= 0; --i) {
            f[i] = max(values[i] - f[i+1], values[i]+values[i+1] - f[i+2]);
        }
        
        return f[0] > 0;
    }
};

