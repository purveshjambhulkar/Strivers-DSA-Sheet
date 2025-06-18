
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for (int i = 0; i < 4; ++i) {
                int n_row = row + drow[i];
                int n_col = col + dcol[i];

                if (n_row >= 0 && n_row < m && n_col >= 0 && n_col < n) {
                    if (!visited[n_row][n_col]) {
                        visited[n_row][n_col] = true;
                        q.push({{n_row, n_col}, steps + 1});
                    }
                }
            }
        }

        return dist;
    }
};