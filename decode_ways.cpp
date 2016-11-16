class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        int len = s.size();
        if (len == 0 || s[0] == '0') return 0;
        if (len == 1) return 1;
        
        int result = 0, fn_1 = 1, fn_2 = 1;
        for (int i = 1; i < len; ++i) {
            int temp = fn_1;
            
            if (!isValid(s[i]) && !isValid(s[i-1], s[i])) return 0;
            
            if (isValid(s[i])) result += fn_1;
            if (isValid(s[i-1], s[i])) result += fn_2;
            
            fn_1 = result;
            fn_2 = temp;
            result = 0;
        }
        return fn_1;
    }
    
    bool isValid(char c) {
        return c != '0';
    }
    
    bool isValid(char c1, char c2) {
        return c1 == '1' || (c1 == '2' && c2 <= '6');
    }
};
