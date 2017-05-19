class Solution {
public:
    /**
     * @param s a string
     * @return it's index
     */
    int firstUniqChar(string& s) {
        unordered_map<char, int> mp;
        for (const auto& c : s) {
            mp[c]++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (mp[s[i]] == 1) return i;
        }
        return -1;
    }
};
