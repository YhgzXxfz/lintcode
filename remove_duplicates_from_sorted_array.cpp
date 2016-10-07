class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        
        if (len <= 1) return len;
        
        int count = 0;
        for (int i = 0; i < len-1; ++i) {
            if (nums[i+1] == nums[i]) {
                ++count;
            } else {
                nums[i+1 - count] = nums[i+1];
            }
        }
        return len-count;
    }
};

