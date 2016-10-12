class Solution {
public:
    /**
    * Calculate the total number of distinct N-Queen solutions.
    * @param n: The number of queens.
    * @return: The total number of distinct solutions.
    */
    int totalNQueens(int n) {
        // write your code here
        int count = 0;
        vector<string> solution(n, string(n, '.'));
        SolveNQueens(solution, 0, n, count);
        return count;
    }
 
    void SolveNQueens(vector<string>& solution, int row, int n, int& count) {
        if (row == n) {
            ++count;
            return;
        }
     
        for (int col = 0; col != n; ++col) {
            if (IsValid(solution, row, col, n)) {
                solution[row][col] = 'Q';
                SolveNQueens(solution, row+1, n, count);
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


