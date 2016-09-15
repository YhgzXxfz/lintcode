class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        
        if (n <= 1) return 0;
        if (n == 2) return 1;
        
        int x1 = 0, x2 = 1;
        int temp;
        for (int i = 3; i <= n; ++i)
        {
            temp = x1 + x2;
            x1 = x2;
            x2 = temp;
        }
        return x2;
    }
};


