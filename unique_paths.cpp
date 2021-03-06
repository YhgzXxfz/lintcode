class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if (m < 1 || n < 1) return 0;
        
        vector<vector<int>> paths(m+1, vector<int> (n+1, 0));
        //for (int i = 0; i <= m; ++i) paths[i][0] = 1;
        //for (int j = 0; j <= n; ++j) paths[0][j] = 1;
        paths[0][1] = 1;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m][n];
    }
};


