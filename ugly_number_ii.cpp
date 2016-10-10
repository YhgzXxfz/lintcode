class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long nthUglyNumber(int k) {
        // write your code here
        if (k <= 0) return 0;
        
        long long result[k+1];
        result[0] = 1;
        result[1] = 2;
        result[2] = 3;
        result[3] = 4;
        
        int last2 = 0, last3 = 0, last5 = 0;
        for (int i = 4; i < k; ++i) {
            long long prev = result[i-1];
            
            while(result[last2]*2 <= prev) last2++;
            while(result[last3]*3 <= prev) last3++;
            while(result[last5]*5 <= prev) last5++;
            
            long long candidate2 = result[last2]*2;
            long long candidate3 = result[last3]*3;
            long long candidate5 = result[last5]*5;
            
            result[i] = min(candidate2, min(candidate3, candidate5));
        }
        return result[k-1];
    }
};

