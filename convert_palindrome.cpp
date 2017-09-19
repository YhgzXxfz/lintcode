class Solution {
public:
    /*
     * @param : String
     * @return: String
     */
    string convertPalindrome(string s) {
        string rev = s;
        int len = s.size();
        reverse(rev.begin(), rev.end());
        int pos;
        for (pos = len; pos >= 0; --pos) {
            if (rev.substr(len-pos) == s.substr(0, pos)) break;
        }
        return rev.substr(0, len-pos) +s;
    }
};
