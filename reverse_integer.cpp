class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long temp = 0;
        bool minus = false;
        
        if (n < 0) {
            n = abs(n);
            minus = true;
        }
        
        while (n > 0) {
            temp = temp*10 + n%10;
            n /= 10;
        }
        
        if (!minus) {
            if (temp > INT_MAX) return 0;
        } else {
            if (temp > 0x80000000) return 0;
        }
        
        return minus ? (-1)*(int)temp : (int)temp;
    }
};

