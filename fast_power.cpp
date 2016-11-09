class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        return FastPower(a%b, b, n);
    }
    
    long long FastPower(long long a, int b, int n) {
        if (0 == n) return 1%b;
        if (n % 2 == 0) return FastPower((a*a) %b, b, n/2);
        else return (a * FastPower((a*a) %b, b, n/2)) %b;
    }
};

