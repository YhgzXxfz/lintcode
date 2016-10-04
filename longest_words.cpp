class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int len = dictionary.size();
        if (len <= 1) return dictionary;
        
        int length;
        vector<string> result;
        int maximum = -1;
        for (int i = 0; i < len; ++i)
        {
            length = dictionary[i].size();
            if (length > maximum)
            {
                maximum = length;
                result.clear();
                result.push_back(dictionary[i]);
            }
            else if (length == maximum)
            {
                result.push_back(dictionary[i]);
            }
        }
        return result;
        
    }
};

