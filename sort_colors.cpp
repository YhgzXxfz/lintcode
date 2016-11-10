class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int len = nums.size(), lastZero = -1, firstTwo = nums.size();
        
        int i = 0;
        while (i < firstTwo) {
            if (nums[i] == 2) {
                --firstTwo;
                swap(nums[i], nums[firstTwo]);
            } else if (nums[i] == 0) {
                ++lastZero;
                swap(nums[i], nums[lastZero]);
                ++i;
            } else {
                ++i;
            }
        }
    }
};

