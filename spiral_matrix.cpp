class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> result;
        if (matrix.empty()) return result;
        
        for (int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
            top <= bottom && left <= right;
            ++top, --bottom, ++left, --right) {
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            
            for (int i = top+1; i < bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            
            for (int j = right; j >= left && top<bottom; --j) {
                result.push_back(matrix[bottom][j]);
            }
            
            for (int i = bottom-1; i > top && left < right; --i) {
                result.push_back(matrix[i][left]);
            }
        }
        return result;
    }
};
