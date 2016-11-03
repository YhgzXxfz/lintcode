class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int len = s.size();
        
        unordered_set<char> chrs;
        for (const auto& word : dict) {
            for (const auto& c : word) {
                chrs.emplace(c);
            }
        }
        for (const auto& c : s) {
            if (!chrs.count(c)) return false;
        }
        
        
        vector<bool> f(len+1, false);
        f[0] = true;
        
        for (int i = 1; i <= len; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (f[j] && dict.count(s.substr(j,i-j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};

