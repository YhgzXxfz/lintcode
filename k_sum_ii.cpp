class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> solution;
        
        dfs(result, solution, 0, target, k, A);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& solution, int step, int gap, int k, vector<int> A) {
        if (k < 0 || gap < 0) return;
        
        if (k == 0 && gap == 0) {
            result.push_back(solution);
            return ;
        }
        
        for (int i = step; i < A.size(); ++i) {
            solution.push_back(A[i]);
            dfs(result, solution, i+1, gap-A[i], k-1, A);
            solution.pop_back();
        }
    }
};


