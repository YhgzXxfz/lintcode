class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, const string word, int x, int y, int index) {
        if (word.size() == index) return true;
        
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if (board[x][y] != word[index]) return false;
        
        char t = board[x][y];
        board[x][y] = '\0';
        bool result =   dfs(board, word, x+1, y, index+1) ||
                        dfs(board, word, x, y+1, index+1) ||
                        dfs(board, word, x-1, y, index+1) ||
                        dfs(board, word, x, y-1, index+1);
        board[x][y] = t;
        
        return result;
    }
};

