class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int n = matrix.size();
        
        // diagonal inversion
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-i; ++j) {
                swap(matrix[i][j], matrix[n-1 -j][n-1 -i]);
            }
        }
        
        // up-down inversion
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n-1 -i][j]);
            }
        }
    }
};

