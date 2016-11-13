class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        int len = strs.size();
        if (len <= 1) return strs;
        
        vector<bool> keys (len, true);
        vector<string> temp = strs;
        
        for (int i = 0; i < len ; ++i) {
            sort(temp[i].begin(), temp[i].end());
        }
        
        vector<string> result;
        
        for (int i = 0; i < len -1; ++i) {
            if (keys[i]) {
                for (int j = i+1; j < len; ++j) {
                    if (temp[i] == temp[j] && keys[j]) {
                        result.push_back(strs[j]);
                        keys[j] = false;
                        keys[i] = false;
                    }
                }
                if (!keys[i]) result.push_back(strs[i]);
            }
        }
        return result;
    }
};


