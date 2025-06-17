class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Queue to hold ((row, col), time)
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int freshCount = 0;

        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int maxTime = 0;
        int rottedCount = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxTime = max(maxTime, time);

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                // Check bounds and if it is a fresh orange
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {

                    q.push({{newRow, newCol}, time + 1});
                    visited[newRow][newCol] = 2;
                    rottedCount++;
                }
            }
        }

        // If some fresh oranges were never rotted
        if (rottedCount != freshCount) return -1;
        return maxTime;
    }
};
