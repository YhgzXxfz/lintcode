class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        
        int non_zero = 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != 0) {
                nums[non_zero] = nums[i];
                non_zero++;
            }
        }
        
        while (non_zero < len) {
            nums[non_zero] = 0;
            non_zero++;
        }
    }
};
