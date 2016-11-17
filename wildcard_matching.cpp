class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        const char* star = nullptr;
        const char* ss = s;
        
        while (*s) {
            if (*p == '?' || *p == *s) {
                s++; p++; 
                continue;
            }
            if (*p == '*') {
                star = p; p++;
                ss = s; 
                continue;
            }
            if (star) {
                p = star+1;
                ++ss; 
                s = ss;
                continue;
            }
            return false;
        }
        while (*p == '*') p++;
        return !*p;
    }
};

