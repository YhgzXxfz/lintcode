class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int len = nums.size();
        
        int cn1 = 0, cn2 = 0;
        int major1, major2;
        
        for (int n : nums) {
            if (cn1 == 0 || major1 == n) {
                ++cn1;
                major1 = n;
            } else if (cn2 == 0 || major2 == n) {
                ++cn2;
                major2 = n;
            } else {
                --cn1;
                --cn2;
            }
        }
        
        cn1 = 0; cn2 = 0;
        for (int n : nums) {
            if (n == major1) ++cn1;
            else if (n == major2) ++cn2;
        }
        
        
        if (cn1 > len/3) return major1;
        if (cn2 > len/3) return major2;
    }
};


