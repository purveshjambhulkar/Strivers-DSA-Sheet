// this problem is similar to Surrounded Regions | Replace O's with X's
//  lets solve this with same approach

// Approach
// TLDR -
// call dfs traversal for all the land cell at the boundary and mark them as *
// now traverse the matrix and count the number of 1s and return the count

class Solution {
public:
    void dfsUtil(vector<vector<int>>& board, int i, int j, int rows,
                 int cols) {

        // base case
        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 1) {
            return;
        }

        board[i][j] = 9;

        // recursive call
        dfsUtil(board, i + 1, j, rows, cols);
        dfsUtil(board, i, j + 1, rows, cols);
        dfsUtil(board, i - 1, j, rows, cols);
        dfsUtil(board, i, j - 1, rows, cols);
    }

    void traverseBorder(vector<vector<int>>& board, int rows, int cols) {
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 1) {
                dfsUtil(board, 0, i, rows, cols);
            }
            if (board[rows - 1][i] == 1) {
                dfsUtil(board, rows - 1, i, rows, cols);
            }
        }

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 1) {
                dfsUtil(board, i, 0, rows, cols);
            }
            if (board[i][cols - 1] == 1) {
                dfsUtil(board, i, cols - 1, rows, cols);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        traverseBorder(grid , rows , cols);

        int count = 0;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;


    }
};