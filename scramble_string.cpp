class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        return isScrambleString(s1, s2);
    }
    
    bool isScrambleString(string s1, string s2) {
        // Write your code here
        if (s1 == s2) return true;
        
        int len = s1.size();
        int count[26] = {0};
        for (int i = 0;i < len; ++i) {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for (int i = 0;i < 26; ++i) {
            if (count[i] != 0) return false;
        }
        
        for (int i = 1; i < len; ++i) {
            if (isScrambleString(s1.substr(0,i), s2.substr(0,i)) &&
                isScrambleString(s1.substr(i), s2.substr(i)))  return true;
            
            if (isScrambleString(s1.substr(0,i), s2.substr(len-i)) &&
                isScrambleString(s1.substr(i), s2.substr(0,len-i))) return true;
        }
        return false;
    }
};
