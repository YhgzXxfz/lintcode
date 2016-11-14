class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        
        int len = nums.size();
        int k = -1;
        for (int i = len-2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                k = i;
                break;
            }
        }
        if (k == -1)  {
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        int l = -1;
        for (int i = len-1; i >= 0; --i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[l], nums[k]);
        
        reverse(nums.begin() + k+1, nums.end());
    }
};

