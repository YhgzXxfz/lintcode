class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if (n == 0) return 1;
        if (n == 1) return x;
        
        bool is_pos = n > 0 ? true : false;
        n = abs(n);
        double result;
        
        if (n % 2) {
            result = myPow(x, n/2);
            result *= result;
            result *= x;
        } else {
            result = myPow(x, n/2);
            result *= result;
        }
        
        return is_pos ? result : 1/result;
    }
};

