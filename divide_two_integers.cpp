class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0) return INT_MAX;
        bool is_neg = (dividend < 0) ^ (divisor < 0);
        
        int result = 0;
        if (dividend == INT_MIN) {
            if(divisor == -1) return INT_MAX;
            
            dividend += abs(divisor);
            result++;
        }
        if (divisor == INT_MIN) return result;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        int step = 0;
        while (divisor <= (dividend>>1)) {
            divisor <<= 1;
            step++;
        }
        while (step >= 0) {
            if (dividend >= divisor) {
                result += 1<<step;
                dividend -= divisor;
            }
            divisor >>= 1;
            step--;
        }
        return is_neg ? -result : result;
    }
};

