class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> left;
        int len = s.size();
        
        char expected;
        for (int i = 0; i < len; ++i)
        {
            char c = s[i];
            switch (c)
            {
                case '(': 
                case '[': 
                case '{': 
                    left.push(c);
                    break;
                
                case ')': expected = '('; break;
                case ']': expected = '['; break;
                case '}': expected = '{'; break;
                    
            }
            if (c == ')' || c == ']' || c == '}')
            {
                if (left.empty() || expected != left.top()) return false;
                left.pop();
            }
        }
        return left.empty();
    }
};

