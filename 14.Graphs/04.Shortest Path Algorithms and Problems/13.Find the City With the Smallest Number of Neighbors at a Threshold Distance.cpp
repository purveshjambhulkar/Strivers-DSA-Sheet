class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9; // Avoid using INT_MAX

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cityNo = -1;
        int cityCount = n;

        for (int i = 0; i < n; i++) {
            int tempCount = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    tempCount++;
                }
            }

            // Prefer the city with the greatest index in case of tie
            if (tempCount <= cityCount) {
                cityCount = tempCount;
                cityNo = i;
            }
        }

        return cityNo;
    }
};
