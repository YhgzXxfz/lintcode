class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int len1 = word1.size();
        int len2 = word2.size();
        
        vector<vector<int>> f(len1+1, vector<int>(len2+1, 0));
        
        for (int i = 0; i <= len1; ++i) {
            f[i][0] = i;
        }
        
        for (int j = 0; j <= len2; ++j) {
            f[0][j] = j;
        }
        
        
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    f[i][j] = f[i-1][j-1];
                } else {
                    f[i][j] = 1+ min(f[i-1][j-1], min(f[i-1][j], f[i][j-1]));
                }
            }
        }
        return f[len1][len2];
    }
};


