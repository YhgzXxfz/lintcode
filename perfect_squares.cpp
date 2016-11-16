class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        
        // DP
        /*
        if (n < 1) return 0;
        static vector<int> result({0});
        
        while (result.size() <= n) {
            int count = INT_MAX, len = result.size();
            for (int i = 1; i*i <= len; ++i) {
                count = min(count, 1+result[len-i*i]);
            }
            result.push_back(count);
        }
        return result[n];
        */
        
        // Maths
        if (n < 1) return 0;
        
        int sqrtN = sqrt(n);
        for (int i = 0; i <= sqrtN; ++i) {
            for (int j = i ;j <= sqrtN; ++j) {
                int k = sqrt(n - i*i -j*j);
                if (i*i + j*j + k*k == n) return !!i + !!j + !!k;
            }
        }
        return 4;
    }
};
