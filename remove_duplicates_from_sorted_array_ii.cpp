class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        
        if (len <= 2) return len;
        
        int dup_count = 1;
        int pos = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != nums[i-1]) {
                dup_count = 1;
                nums[pos] = nums[i];
                ++pos;
            } else {
                if (dup_count < 2) {
                    ++dup_count;
                    nums[pos] = nums[i];
                    ++pos;
                }
            }
        }
        return pos;
    }
};

