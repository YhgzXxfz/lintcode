class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	sort(nums.begin(), nums.end());
    	
    	vector<vector<int>> result;
    	vector<int> solution;
    	
    	SelectSubsets(result, nums, solution, 0);
    	return result;
    }
    
private:
    void SelectSubsets(vector<vector<int>> & result, vector<int> & nums, vector<int> & solution, int begin) {
        result.push_back(solution);
        for (int i = begin; i != nums.size(); ++i)
        {
            solution.push_back(nums[i]);
            SelectSubsets(result, nums, solution, i+1);
            solution.pop_back();
        }
    }
    
    
};

