class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        if (n == 0) return result;
        
        for (int i = 0; i < m + n - 1; ++i) {
            if (i % 2) {
                for (int y = min(i, n - 1);  y >= max(0, i - m + 1); --y) {
                    result.emplace_back(matrix[i - y][y]);
                }
            } else {
                for (int x = min(i, m - 1);  x >= max(0, i - n + 1); --x) {
                    result.emplace_back(matrix[x][i - x]);
                }
            }
        }
        return result;
    }
};

