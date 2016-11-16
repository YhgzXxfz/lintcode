class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if (str.empty()) return 0;
        
        int result = 0, i = 0, sign = 1;
        
        while (str[i] == ' ') ++i;
        
        if (str[i] == '+') ++i;
        else if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        
        for (; i < str.size() && isdigit(str[i]); ++i) {
            if (result > (INT_MAX - (str[i]-'0'))/10)
                return sign > 0 ? INT_MAX : INT_MIN;
            
            result *= 10;
            result += str[i] - '0';
        }
        return result*sign;
    }
};

