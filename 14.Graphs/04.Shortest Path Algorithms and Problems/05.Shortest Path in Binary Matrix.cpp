//APPROACH 2 - OPTIMISED 

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 1;

        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return dist[x][y];

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};



//APPROACH 1 - MEMORY LIMIT EXCEDDED

// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         int rows = grid.size();
//         int cols = grid[0].size();

//         int srcCol = 0;
//         int srcRow = 0;

//         int distRow = rows - 1;
//         int distCol = cols - 1;

//         if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) {
//             return -1;
//         }

//         // 2. Edge Case: If the grid is 1x1 and the cell is clear (value is 0)
//         // The path length is 1 (the cell itself).
//         if (rows == 1 && cols == 1 && grid[0][0] == 0) {
//             return 1;
//         }


//         vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

//         // pair<dist ,{row , col}>
//         queue<pair<int, pair<int, int>>> q;

//         dist[0][0] = 0;

//         q.push({0, {0, 0}});

//         int rowArr[] = {-1, 0, 1, 0, -1, 1, 1, -1};
//         int colArr[] = {0, 1, 0, -1, 1, 1, -1, -1};

//         while (!q.empty()) {
//             int r = q.front().second.first;
//             int c = q.front().second.second;
//             int d = q.front().first;

//             q.pop();

//             for (int i = 0; i < 8; i++) {
//                 int tempr = r + rowArr[i];
//                 int tempc = c + colArr[i];

//                 if (tempr >= 0 && tempc >= 0 && tempr < rows && tempc < cols &&
//                     grid[tempr][tempc] == 0 && d + 1 < dist[tempr][tempc]) {

//                     if (tempr == distRow && tempc == distCol) {
//                         return d + 2;
//                     }
//                     q.push({d + 1, {tempr, tempc}});
//                 }
//             }
//         }

//         return -1;
//     }
// };