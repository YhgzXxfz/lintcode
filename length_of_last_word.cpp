class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int len = s.size();
        
        int count = 0;
        for (int i = len-1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (count) break;
                else continue;
            } else {
                ++count;
            }
        }
        
        return count;
    }
};

