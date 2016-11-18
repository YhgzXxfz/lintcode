/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        // write your code here
        if (expression.empty()) return nullptr;
        
        vector<string> prefix;
        infixToPrefix(expression, prefix);
        
        int start = 0;
        return buildExpressionTree(prefix, start);
    }
    
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto& tok : infix) {
            if (atoi(tok.c_str())) prefix.push_back(tok);
            else if (tok == ")") s.push(tok);
            else if (tok == "(") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == ")") break;
                    prefix.push_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) < precedence(s.top())) {
                    prefix.push_back(s.top());
                    s.pop();
                }
                s.push(tok);
            }
        }
        while (!s.empty()) {
            prefix.push_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }
    
    int precedence(string s) {
        if (s == ")") return 0;
        if (s == "+" || s == "-") return 1;
        if (s == "*" || s == "/") return 2;
        return 3;
    }
    
    ExpressionTreeNode* buildExpressionTree(vector<string>& prefix, int& start) {
        if (prefix.empty()) return nullptr;
        
        ExpressionTreeNode* root = new ExpressionTreeNode(prefix[start]);
        ++start;
        
        if (isOperator(prefix[start-1])) {
            root->left = buildExpressionTree(prefix, start);
            root->right = buildExpressionTree(prefix, start);
        }
        return root;
    }
    
    bool isOperator(const string& s) {
        return s.size() == 1 && string("+-*/").find(s) != string::npos;
    }
};

