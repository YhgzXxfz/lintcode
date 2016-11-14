class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int len = s.size();
        if (len <= 1) return s;
        
        int P[len][len];
        memset(P, 0, len*len*sizeof(int));
        int max_len = 0, start, end;
        for (int i = 0; i < len; ++i) {
            P[i][i] = 1;
            for (int j = 0; j < i; ++j) {
                if (i == j) P[j][i] = 1;
                else if (i-j == 1) P[j][i] = (s[i] == s[j]);
                else P[j][i] = (s[i] == s[j]) && P[j+1][i-1];
                
                if ((i+1 - j > max_len) && P[j][i]) {
                    start = j;
                    end = i;
                    max_len = i+1 - j;
                }
            }
        }
        return s.substr(start, max_len);
    }
};

