class Solution {
    public:
        void nQueenUtil(int n, vector<vector<string>>& ans, vector<string> board,
                        vector<int> rowVisit, vector<int> upperDVisit,
                        vector<int> lowerDVisit, int col) {
            // base case
            if (col == n) {
                ans.push_back(board);
                return;
            }
    
            for (int row = 0; row < n; row++) {
    
                if (rowVisit[row] == 0 && upperDVisit[n - 1 + row - col] == 0 &&
                    lowerDVisit[row + col] == 0) {
    
                    board[row][col] = 'Q';
                    rowVisit[row] = 1;
                    upperDVisit[n - 1 + row - col] = 1;
                    lowerDVisit[row + col] = 1;
    
                    // recursive call
                    nQueenUtil(n, ans, board, rowVisit, upperDVisit, lowerDVisit,
                               col + 1);
    
                    // backtrack
    
                    board[row][col] = '.';
                    rowVisit[row] = 0;
                    upperDVisit[n - 1 + row - col] = 0;
                    lowerDVisit[row + col] = 0;
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> ans;
            vector<string> board(n);
            string str(n, '.');
            for (int i = 0; i < n; i++) {
                board[i] = (str);
            }
    
            vector<int> rowVisit(n, 0);
            vector<int> upperDVisit(2 * n - 1, 0);
            vector<int> lowerDVisit(2 * n - 1, 0);
    
            nQueenUtil(n, ans, board, rowVisit, upperDVisit, lowerDVisit, 0);
            return ans;
        }
    };