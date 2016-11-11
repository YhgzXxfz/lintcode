class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n < 0) return 0;
        
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        
        for (int k = 2; k <= n; ++k) {
            for (int i = 1; i <= k; ++i) {
                f[k] += f[i-1] * f[k-i];
            }
        }
        return f[n];
    }
};

