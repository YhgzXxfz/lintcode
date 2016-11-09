class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        
        dfs(result, solution, candidates, target, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& solution, 
        vector<int>& nums, int gap, int start) {
        if (gap == 0) {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (gap < nums[i]) return;
            
            solution.push_back(nums[i]);
            dfs(result, solution, nums, gap-nums[i], i);
            solution.pop_back();
        }
    }
};

