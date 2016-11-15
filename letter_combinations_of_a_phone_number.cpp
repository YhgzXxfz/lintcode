class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> result;
        if (digits.size() == 0) return result;
        string solution;
        
        string table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(result, solution, 0, table, digits);
        return result;
    }
    
    void dfs(vector<string>& result, string& solution, int level, 
        string table[], string& digits) {
        if (level == digits.size()) {
            result.push_back(solution);
            return ;
        }
        
        int curr_digit = digits[level] - '0';
        for (int i = 0; i < table[curr_digit].size(); ++i) {
            solution.push_back(table[curr_digit][i]);
            dfs(result, solution, level+1, table, digits);
            solution.pop_back();
        }
    }
};

