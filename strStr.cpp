class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if (!source || !target) return -1;
        
        int lenS = length(source);
        int lenT = length(target);
        if (lenS < lenT) return -1;
        
        if (*target == '\0') return 0;
        
        for (int i = 0; i <= lenS-lenT; ++i) {
            if (isEqual(source+i, target, lenT)) return i;
        }
        
        return -1;
    }
    
    bool isEqual(const char * a, const char * b, int lenA) {
        int lenB = length(b);
        if (lenA != lenB) return false;
        
        for (int i = 0; i < lenA; ++i)
        {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    
    int length (const char * str) {
        int len = 0;
        while (str[len] != '\0')
        {
            len++;
        }
        return len;
    }
};


