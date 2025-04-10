class Solution {
    public:
        bool isSafe(vector<vector<char>>& board, int i, int j, char c) {
            for (int ind = 0; ind < 9; ind++) {
                // Check the column
                if (board[ind][j] == c) return false;
    
                // Check the row
                if (board[i][ind] == c) return false;
    
                // Check the 3x3 subgrid
                int rowStart = 3 * (i / 3) + ind / 3;
                int colStart = 3 * (j / 3) + ind % 3;
                if (board[rowStart][colStart] == c) return false;
            }
            return true;
        }
    
        bool sudokuUtil(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        for (char c = '1'; c <= '9'; c++) {
                            if (isSafe(board, i, j, c)) {
                                board[i][j] = c;
    
                                if (sudokuUtil(board)) {
                                    return true;
                                } else {
                                    board[i][j] = '.';
                                }
                            }
                        }
                        return false; // If no number fits, backtrack
                    }
                }
            }
            return true;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            sudokuUtil(board);
        }
    };
    