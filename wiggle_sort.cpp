class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        
        for (int i = 1; i < len; ++i)
        {
            if ((i&1) && (nums[i] < nums[i-1]) || !(i&1) && (nums[i] > nums[i-1]))
                swap(nums[i], nums[i-1]);
        }
    }
};
