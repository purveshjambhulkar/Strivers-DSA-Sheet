class Solution {
public:
    // APPROACH 3 - O(N^2)

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    
    }
    // // APPROACH 2 - O(N^2)

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();
    //     std::vector<int> row(rows, 0);
    //     std::vector<int> col(cols, 0);
    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (matrix[i][j] == 0) {
    //                 row[i] = 1;
    //                 col[j] = 1;
    //             }
    //         }
    //     }

    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (row[i] || col[j]) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // APPROACH 1 - O(N^3)

    // void markRow(int row, int cols, vector<vector<int>>& matrix) {
    //     for (int i = 0; i < cols; i++) {
    //         if (matrix[row][i] != 0) {
    //             matrix[row][i] = 999;
    //         }
    //     }
    // }

    // void markCol(int rows, int col, vector<vector<int>>& matrix) {
    //     for (int i = 0; i < rows; i++) {
    //         if (matrix[i][col] != 0) {
    //             matrix[i][col]= 999;
    //         }
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int rows = matrix.size();
    //     int cols = matrix[0].size();

    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (matrix[i][j] == 0) {
    //                 markRow(i, cols, matrix);
    //                 markCol(rows, j, matrix);
    //             }
    //         }
    //     }

    //     for (int i = 0; i < rows; i++) {
    //         for (int j = 0; j < cols; j++) {
    //             if (matrix[i][j] == 999) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }
};