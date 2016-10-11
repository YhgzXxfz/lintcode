class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> nums = S;
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> solution;
        
        SelectSubsetsWithDup(result, solution, 0, nums);
        return result;
    }
    
    void SelectSubsetsWithDup(vector<vector<int>> & result, vector<int> & solution, 
        int begin, vector<int> & nums) {
        result.push_back(solution);
        for (int i = begin; i != nums.size(); ++i) {
            if (i == begin || (i > begin && nums[i] != nums[i-1])) {
                solution.push_back(nums[i]);
                SelectSubsetsWithDup(result, solution, i+1, nums);
                solution.pop_back();
            }
        }
    }
};


