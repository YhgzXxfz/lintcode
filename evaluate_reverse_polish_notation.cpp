class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if (tokens.empty()) return 0;
        
        stack<string> s;
        
        for (const auto &c : tokens) {
            if (!isOperator(c)) s.push(c);
            else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                switch(c[0]) {
                    case '+' : x += y; break;
                    case '-' : x -= y; break;
                    case '*' : x *= y; break;
                    case '/' : x /= y; break;
                }
                s.push(to_string(x));
            }
        }
        return stoi(s.top());
    }
    
    bool isOperator(string c) {
        return c.size() == 1 && string("+-*/").find(c) != string::npos;
    }
};

