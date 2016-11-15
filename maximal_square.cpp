class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        // 1
        /*
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        
        int maxLen = 0;
        vector<vector<int>> p(m, vector<int> (n, 0));
        
        for (int i = 0; i < m; ++i) {
            p[i][0] = matrix[i][0];
            maxLen = max(maxLen, p[i][0]);
        }
        
        for (int j = 0; j < n; ++j) {
            p[0][j] = matrix[0][j];
            maxLen = max(maxLen, p[0][j]);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    p[i][j] = min(p[i-1][j-1], min(p[i-1][j], p[i][j-1])) +1;
                    maxLen = max(maxLen, p[i][j]);
                }
            }
        }
        
        return maxLen * maxLen;
        */
        
        // 2
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> prev (m, 0);
        vector<int> curr (m, 0);
        
        int len = 0;
        
        for (int i = 0; i < m; ++i) {
            prev[i] = matrix[i][0];
            len = max(len, prev[i]);
        }
        
        for (int j = 1; j < n; ++j) {
            curr[0] = matrix[0][j];
            len = max(len, curr[0]);
            for (int i = 1; i < m; ++i) {
                if (matrix[i][j] == 1) {
                    curr[i] = min(curr[i-1], min(prev[i-1], prev[i])) +1;
                    len = max(len, curr[i]);
                }
            }
            swap (prev, curr);
            fill(curr.begin(), curr.end(), 0);
        }
        
        return len * len;
    }
};

