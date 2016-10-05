class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len <= 1) return;
        
        int left = 0, right = len-1;
        while (left < right) {
            if (nums[left] %2) {
                left++;
                continue;
            }
            
            if (nums[right] %2 == 0) {
                right--;
                continue;
            }
            
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};

