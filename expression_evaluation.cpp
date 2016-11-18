class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        if (expression.empty()) return 0;
        
        stack<int> operands;
        stack<string> operators;
        
        for (int i = expression.size()-1; i >= 0; --i) {
            string s = expression[i];
            if (isdigit(s[0])) operands.push(stoi(s));
            else if (s == ")" || s == "*" || s == "/") {
                operators.push(s);
            } else if (s == "+" || s == "-") {
                while(!operators.empty() && 
                    (operators.top() == "*" || operators.top() == "/")) {
                    compute(operands, operators);
                }
                operators.push(s);
            } else if (s == "(") {
                while (operators.top() != ")") {
                    compute(operands, operators);
                }
                operators.pop();
            }
        }
        
        while (!operators.empty()) {
            compute(operands, operators);
        }
        return operands.top();
    }
    
    void compute(stack<int>& operands, stack<string>& operators) {
        int left = operands.top();
        operands.pop();
        int right = operands.top();
        operands.pop();
        string op = operators.top();
        operators.pop();
        
        switch(op[0]) {
            case '+' : operands.push(left+right); break;
            case '-' : operands.push(left-right); break;
            case '*' : operands.push(left*right); break;
            case '/' : operands.push(left/right); break;
        }
    }
};

