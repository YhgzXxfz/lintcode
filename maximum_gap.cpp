class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        // write your code here
        int len = nums.size();
        if (len < 2) return 0;
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        int max_diff = 0;
        for (int i = 1; i < len; ++i) {
            int diff = copy[i] - copy[i-1];
            max_diff = max(max_diff, diff);
        }
        return max_diff;
    }
};

