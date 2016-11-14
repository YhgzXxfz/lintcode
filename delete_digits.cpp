class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        int len = A.size();
        if (k >= len) return "0";
        
        stack<char> s;
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && k > 0 && s.top() > A[i]) {
                s.pop();
                --k;
            }
            s.push(A[i]);
        }
        
        while (k > 0) {
            s.pop();
            --k;
        }
        
        string result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        
        int no_zero_head = 0;
        while(no_zero_head < result.size() && result[no_zero_head] == '0') ++no_zero_head;
        result = result.substr(no_zero_head);
        
        if (result.size() == 0) return "0";
        return result;
    }
};


