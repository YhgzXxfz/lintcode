class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) return false;
        
        int dict[256] = {};
        for (int i = 0; i < s.size(); ++i) {
            dict[s[i]-'\0']++;
            dict[t[i]-'\0']--;
        }
        
        for (int i = 0; i < 256; ++i) {
            if (dict[i] != 0) return false;
        }
        return true;
    }
};

