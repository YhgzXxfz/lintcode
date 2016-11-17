class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if (!*p) return !*s;
        if (p[1] == '*') return isMatch(s, p+2) || (*p == '.' && *s || *s == *p) && isMatch(s+1, p);
        if (*p == '.') return *s && isMatch(s+1, p+1);
        return *s == *p && isMatch(s+1, p+1);
    }
};

