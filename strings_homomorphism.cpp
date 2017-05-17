class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if the characters in s
     * can be replaced to get t or false
     */
    bool isIsomorphic(string& s, string& t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < s.size(); ++i) {
            mp1[s[i]]++;
            mp2[t[i]]++;
            
            if (mp1[s[i]] != mp2[t[i]]) return false;
        }
        return true;
    }
};
