class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        int usedRows[9][9] = {0}, usedCols[9][9] = {0}, usedSubSquare[9][9] = {0};
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0 ; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' -1;
                    int k = i /3 *3 + j/3;
                    if (usedRows[i][num] 
                        || usedCols[j][num] 
                        || usedSubSquare[k][num]) return false;
                    
                    usedRows[i][num] = usedCols[j][num] = usedSubSquare[k][num] = 1;
                }
            }
        }
        return true;
    }
};

