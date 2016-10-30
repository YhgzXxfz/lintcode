class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0) return "";

        auto prefix_len = strs[0].length();
        for (int i = 0; i < prefix_len; ++i) {
            for (const auto& str : strs) {
                if (str[i] != strs[0][i]) {
                    prefix_len = i;
                    break;
                }
            }
        }

        return strs[0].substr(0, prefix_len);
    }
};

