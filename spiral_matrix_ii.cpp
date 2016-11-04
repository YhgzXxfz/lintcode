class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int num = 1;
        for (int top = 0, bottom = n-1, left = 0, right = n-1;
            top <= bottom && left <= right;
            ++top, --bottom, ++left, --right) {
            for (int j = left; j <= right; ++j) {
                matrix[top][j] = num++;
            }
            
            for (int i = top+1; i < bottom; ++i) {
                matrix[i][right] = num++;
            }
            
            for (int j = right; j >= left && top < bottom; --j) {
                matrix[bottom][j] = num++;
            }
            
            for (int i = bottom-1; i > top && left < right; --i) {
                matrix[i][left] = num++;
            }
        }
        return matrix;
    }
};
