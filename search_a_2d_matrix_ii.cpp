class Solution {
public:
 /**
 * @param matrix: A list of lists of integers
 * @param target: An integer you want to search in matrix
 * @return: An integer indicate the total occurrence of target in the given matrix
 */
 int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        
        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        vector<int> lines;
        for (int i = 0; i < m; ++i)
        {
            if (target >= matrix[i][0]) lines.push_back(i);
        }
        vector<int> columns;
        for (int j = 0; j < n; ++j)
        {
            if (target >= matrix[0][j]) columns.push_back(j);
        }
        
        int count = 0;
        for (int i = lines[0]; i <= lines[lines.size()-1]; ++i)
        {
            for (int j = columns[0]; j <= columns[columns.size()-1]; ++j)
            {
                if (target == matrix[i][j]) ++count;
            }
        }
        
        return count;
    }
};


