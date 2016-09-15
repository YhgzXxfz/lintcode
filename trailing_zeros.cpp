class Solution {
    /*
     * param n: As desciption
     * return: An integer, denote the number of trailing zeros in n!
     */
    public long trailingZeros(long n) {
        // write your code here
        if (n < 0) return 0;
        
        long sum = 0;
        while (n >= 5) {
            sum += n/5;
            n /= 5;
        }
        return sum;
    }
};

