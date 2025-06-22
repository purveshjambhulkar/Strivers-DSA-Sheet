// User function Template for C++

class Solution {
  public:

    void bfsTraversal(vector<vector<int>>& grid, vector<vector<int>>& visited,
                      int rows, int cols, int i, int j,
                      vector<pair<int, int>>& shape) {

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        int base_i = i, base_j = j;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;

            // Store relative position
            shape.push_back({r - base_i, c - base_j});

            for (int k = 0; k < 4; k++) {
                int nrow = r + drow[k];
                int ncol = c + dcol[k];

                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> uniqueShapes;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    bfsTraversal(grid, visited, m, n, i, j, shape);
                    uniqueShapes.insert(shape);
                }
            }
        }

        return uniqueShapes.size();
    }
};
