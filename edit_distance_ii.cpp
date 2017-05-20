class Solution {
public:
    /**
     * @param s a string
     * @param t a string
     * @return true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string& s, string& t) {
        if (s.size() > t.size()) return isOneEditDistance(t, s);
        
        int len_s = s.size(), len_t = t.size(), diff = len_t - len_s;
        if (diff > 1) return false;
        
        int i = 0, j = 0;
        while (i < len_s && j < len_t && s[i] == t[j]) {
            ++i; ++j;
        }
        
        ++j;
        if (diff == 0) ++i;
        while (i < len_s && j < len_t && s[i] == t[j]) {
            ++i; ++j;
        }
        return len_s == i && len_t == j;
    }
};
