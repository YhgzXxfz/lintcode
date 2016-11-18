class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        vector<string> postfix;
        infixToPostfix(expression, postfix);
        return postfix;
    }
    
    void infixToPostfix(vector<string>& infix, vector<string>& postfix) {
        stack<string> s;
        for (auto& tok : infix) {
            if (atoi(tok.c_str())) postfix.push_back(tok);
            else if (tok == "(") s.push(tok);
            else if (tok == ")") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == "(") break;
                    postfix.push_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) <= precedence(s.top())) {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            postfix.push_back(s.top());
            s.pop();
        }
    }
    
    int precedence(string s) {
        if (s == "(") return 0;
        if (s == "+" || s == "-") return 1;
        if (s == "*" || s == "/") return 2;
        return 3;
    }
};

