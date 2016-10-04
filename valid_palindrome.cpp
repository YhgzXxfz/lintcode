class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        int len = s.length();
        if (len <= 1) return true;
        
        string toTest;
        int count = 0;
        for (int i = 0; i < len; ++i)
        {
            char c = s[i];
            if (isDigit(c) || isLowercase(c)) {
                toTest[count] = c;
                count++;
            } else if (isUppercase(c)) {
                toTest[count] = c+32;
                count++;
            } else {
                continue;
            }
        }
        
        for (int i = 0; i < count/2; ++i) {
            if (toTest[i] != toTest[count -1-i]) return false;
        }
        return true;
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    bool isUppercase(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    bool isLowercase(char c) {
        return c >= 'a' && c <= 'z';
    }
};

