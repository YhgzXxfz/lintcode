class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<int> solution;
        vector<vector<int>> result;
        
        dfs(result, solution, 1, n, k);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& solution, int start, int n, int k) {
        if (solution.size() >= k) {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            solution.push_back(i);
            dfs(result, solution, i+1, n, k);
            solution.pop_back();
        }
    }
};

