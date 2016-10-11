class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        if (nums.empty()) return {{}};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int> >result;
        recursion(nums, 0, result);
        return result;
    }
    
    void recursion(vector<int> nums, int begin, vector<vector<int> > &result) 
    {
        if (begin == nums.size()-1) {
            result.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++) {
            if (begin != i && nums[begin] == nums[i]) continue;
            swap(nums[begin], nums[i]);
            recursion(nums, begin+1, result);
        }
    }
};

