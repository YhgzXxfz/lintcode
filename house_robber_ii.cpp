class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        int len = nums.size();
        
        if (len < 2) return len ? nums[0] : 0;
        return max(rob(nums, 0, len-2), rob(nums, 1, len-1));
    }
    
    int rob(vector<int>& nums, int left, int right) {
        if (left > right) return 0;
        
        int prev = 0, curr = 0;
        for (int i = left; i <= right; ++i) {
            int temp = max(curr, prev + nums[i]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
