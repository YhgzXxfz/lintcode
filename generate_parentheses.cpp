class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> results;
        string solution;
        GenerateParenthesis(results, solution, n, 0, 0);
        return results;
    }
    
    void GenerateParenthesis(vector<string> & results, string & solution
        , int n, int left, int right) {
        if (left == n && right == n) {
            results.push_back(solution);
            return;
        }
        
        if (left < n) {
            solution.push_back('(');
            GenerateParenthesis(results, solution, n, left+1, right);
            solution.pop_back();
        }
        
        if (right < left) {
            solution.push_back(')');
            GenerateParenthesis(results, solution, n, left, right+1);
            solution.pop_back();
        }
    }
};

