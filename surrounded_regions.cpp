class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int m = board.size();
        if (m == 0) return ;
        int n = board[0].size();
        
        // only 'O' in four boarders are not surrounded by 'X'
        // check four boarders
        for (int i = 0; i < m; ++i) {
            check(board, i, 0, m, n);
            if (n > 1) check(board, i, n-1, m, n);
        }
        for (int j = 0; j < n; ++j) {
            check(board, 0, j, m, n);
            if (m > 1) check(board, m-1, j, m, n);
        }
        
        // flip values
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
    
    void check(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 0) check(board, i-1, j, m, n);
            if (j > 0) check(board, i, j-1, m, n);
            if (i < m-1) check(board, i+1, j, m, n);
            if (j < n-1) check(board, i, j+1, m, n);
        }
    }
};
