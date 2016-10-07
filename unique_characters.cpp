class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        int len = str.length();
        
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if (str[i] == str[j]) return false;
            }
        }
        return true;
    }
};

