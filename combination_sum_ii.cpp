class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> solution;
        sort(num.begin(), num.end());
        
        dfs(result, solution, num, target, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& solution, 
        vector<int>& nums, int gap, int start) {
        if (gap == 0) {
            result.push_back(solution);
            return;
        }
        
        int prev = -1;
        for (int i = start; i < nums.size(); ++i) {
            if (gap < nums[i]) return;
            
            if (prev == nums[i]) continue;
            prev = nums[i];
            
            solution.push_back(nums[i]);
            dfs(result, solution, nums, gap-nums[i], i+1);
            solution.pop_back();
        }
    }
};

