class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int len = nums.size(), min_length = INT_MAX, sum = 0, begin = 0;
        
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_length = min (min_length, i+1 - begin);
                sum -= nums[begin];
                begin++;
            }
        }
        return min_length == INT_MAX ? -1 : min_length;
    }
};

