class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        if (nums.empty()) return {{}};
        
        vector<vector<int>> result;
        PermuteRecursion(result,  nums, 0);
        return result;
    }
    
private:
    void PermuteRecursion(vector<vector<int>> & result, vector<int> & nums, int begin) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); ++i) {
            swap(nums[i], nums[begin]);
            PermuteRecursion(result, nums, begin+1);
            swap(nums[i], nums[begin]);
        }
    }
};


