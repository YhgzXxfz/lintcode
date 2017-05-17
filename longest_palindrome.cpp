class Solution {
public:
    /**
     * @param s a string which consists of lowercase or uppercase letters
     * @return the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        int letters[52] = {};
        for (char c : s) {
            if (c < 97) letters[c-'A']++;
            else letters[c-'a'+26]++;
        }
        
        int result = 0;
        for (int i = 0; i < 52; ++i) {
            int n = letters[i];
            if (n%2 == 0) result += n;
            else if (result &1) result += n-1;
            else result += n;
        }
        return result;
    }
};
