class Solution {
public:
    /**
     * @param s  an expression includes numbers, letters and brackets
     * @return a string
     */
    string expressionExpand(string& s) {
        int i = 0;
        return dfs(s, i);
    }
    
private:
    string dfs(string& s, int &i) {
        string result;
        int len = s.size();
        while (i < len && s[i] != ']') {
            if (!isdigit(s[i])) {
                result += s[i++];
            } else {
                int num = 0;
                while (i < len && isdigit(s[i])) {
                    num = num*10 + s[i++]-'0';
                }
                
                ++i;
                string nested = dfs(s, i);
                ++i;
                
                while (num-- > 0) {
                    result += nested;
                }
            }
        }
        return result;
    }
};
