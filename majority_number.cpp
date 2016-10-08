class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int result;
        int times = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            if (times == 0) {
                result = nums[i];
                times++;
            } else if (result == nums[i]) {
                times++;
            } else {
                times--;
            }
        }
        return result;
    }
};


