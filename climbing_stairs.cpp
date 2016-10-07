class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (n == 0) return 1;
        if (n <= 3) return n;
        
        int f1 = 1, f2 = 2;
        for (int i = 2; i < n; ++i) {
            f2 = f1 + f2;
            f1 = f2 - f1;
        }
        return f2;
    }
};


