class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> result;
        for (auto num : nums) {
            auto it = lower_bound(result.begin(), result.end(), num);
            if (it == result.end()) result.emplace_back(num);
            else *it = num;
        }
        return result.size();
    }
};


