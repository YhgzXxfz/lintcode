class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> result;
        string solution;
        
        dfs(result, solution, 0, 0, s);
        return result;
    }
    
    void dfs(vector<string>& result, string solution, int start, int step, string s) {
        if (start == s.size() && step == 4) {
            solution.resize(solution.size()-1);
            result.push_back(solution);
            return;
        }
        
        if ((s.size()-start) > (4-step)*3) return;
        if ((s.size()-start) < 4-step) return;
        
        int num = 0;
        for (int i = start; i < start+3; ++i) {
            num = num*10 + (s[i]-'0');
            if (num <= 255) {
                solution += s[i];
                dfs(result, solution+'.', i+1, step+1, s);
            }
            
            if (num == 0) break;
        }
    }
};
