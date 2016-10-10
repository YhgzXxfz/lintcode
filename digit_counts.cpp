class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        long long base = 1, result = 0, last = 0;
        while (n >= base){
            int index = (n / base) % 10;
            long long remain = n - (n / base) * base;
            if (index > k){
                result += index * last + base;
            } else if (index == k){
                result += index * last + remain + 1;
            } else {
                result += index * last;
            }
            last = last * 10 + base;
            base = base * 10;
        }
        return result;
    }
};

