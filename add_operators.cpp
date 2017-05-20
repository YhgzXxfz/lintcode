class Solution {
public:
    /**
     * @param num a string contains only digits 0-9
     * @param target an integer
     * @return return all possibilities
     */
    vector<string> addOperators(string& num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        dfs(num, 0, "", target, result, 0, 0);
        return result;
    }

private:
    void dfs(string& num, int start, string solution, int target, vector<string>& result, long eval, long mul) {
        if (start == num.size()) {
            if (eval == target) result.push_back(solution);
            return ;
        }
        
        for (int i = start; i < num.size(); ++i) {
            if (i != start && num[start] == '0') break;
            
            string curr_str = num.substr(start, i+1-start);
            long curr = stol(curr_str);
            if (start == 0) dfs(num, i+1, solution+curr_str, target, result, curr, curr);
            else {
                dfs(num, i+1, solution+"+"+curr_str, target, result, eval+curr, curr);
                dfs(num, i+1, solution+"-"+curr_str, target, result, eval-curr, -curr);
                dfs(num, i+1, solution+"*"+curr_str, target, result, eval-mul+mul*curr, mul*curr);
            }
        }
    }
};
