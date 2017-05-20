class Solution {
public:
    /**
     * @param s a string
     * @param wordDict a set of words
     */
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        if (mp.find(s) != mp.end()) return mp[s];
        
        vector<string> result;
        
        bool found = false;
        for (int i = s.size()-1; i >= 0; --i) {
            if (wordDict.count(s.substr(i))) {
                found = true;
                break;
            }
        }
        if (!found) return result;
        
        
        if (wordDict.count(s)) result.push_back(s);
        for (int i = s.size()-2; i >= 0; --i) {
            string trial = s.substr(0, i+1);
            if (wordDict.count(trial)) {
                vector<string> rest = wordBreak(s.substr(i+1), wordDict);
                for (const auto& word : rest) {
                    result.push_back(trial + " " + word);
                }
            }
        }
        
        mp[s] = result;
        return mp[s];
    }

private:
    unordered_map<string, vector<string>> mp;
};
