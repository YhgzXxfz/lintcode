class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        //if (n == 1) return false;
        if (n < 0) return false;
        
        int count = 0;
        for (int i = 0 ; i < 32; ++i) {
            count += ((n>>i) & 1);
        }
        return count == 1;
    }
};

