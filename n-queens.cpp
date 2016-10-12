class Solution {
public:
 /**
 * Get all distinct N-Queen solutions
 * @param n: The number of queens
 * @return: All distinct solutions
 * For example, A string '...Q' shows a queen on forth position
 */
 vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> result;
        vector<string> solution(n, string(n, '.'));
        SolveNQueens(result, solution, 0, n);
        return result;
    }
    
    void SolveNQueens(vector<vector<string>> & result, vector<string> & solution, int row, int n) {
        if (row == n) {
            result.push_back(solution);
            return;
        }
        
        for (int col = 0; col != n; ++col) {
            if (IsValid(solution, row, col, n)) {
                solution[row][col] = 'Q';
                SolveNQueens(result, solution, row+1, n);
                solution[row][col] = '.';
            }
        }
    }
    
    bool IsValid(vector<string> & solution, int row, int col, int n) {
        for (int i = 0; i < row; ++i)
            if (solution[i][col] == 'Q') return false;
        
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
            if (solution[i][j] == 'Q') return false;
        
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
            if (solution[i][j] == 'Q') return false;
        
        return true;
    }
};


