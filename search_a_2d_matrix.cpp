class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        int up = 0, down = m-1;
        while (up <= down) {
            int mid = (up+down) /2;
            int mid_number = matrix[mid][0];
            if (target == mid_number) return true;
            else if (target > mid_number) {
                up = mid+1;
            } else {
                down = mid-1;
            }
        }
        int line = down;
        
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = (left+right) /2;
            int mid_number = matrix[line][mid];
            if (target == mid_number) return true;
            else if (target > mid_number) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return false;
    }
};


