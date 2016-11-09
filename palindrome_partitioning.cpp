class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> result;
        if (s.empty()) return result;
        
        vector<string> path;
        getPartition(result, s, 0, path);
        return result;
    }
    
    void getPartition(vector<vector<string>>& result, string& s, int index, vector<string>& path) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i+1 - index));
                getPartition(result, s, i+1, path);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};

