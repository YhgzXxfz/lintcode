class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int dict[256];
        memset(dict, -1, sizeof(dict));
        
        int result = 0, begin = -1;
        int length = s.size();
        
        for (int i = 0; i < length; ++i) {
            char c = s[i];
            if (dict[c] > begin) begin = dict[c];
            
            result = max(result, i-begin);
            dict[c] = i;
        }
        return result;
    }
};

