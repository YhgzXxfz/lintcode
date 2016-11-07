class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int len_t = T.size();
        
        vector<int> f(len_t+1, 0);
        f[0] = 1;
        
        for (int i = 0; i < S.size(); ++i) {
            for (int j = len_t-1; j >= 0; --j) {
                f[j+1] += S[i] == T[j] ? f[j] : 0;
            }
        }
        return f[len_t];
    }
};


