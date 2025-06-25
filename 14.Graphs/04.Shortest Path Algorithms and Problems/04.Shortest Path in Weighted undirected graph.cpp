// problem link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == INT_MAX) return {-1};

        vector<int> path;
        int curr = n;
        while (parent[curr] != curr) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        vector<int> result;
        result.push_back(dist[n]);
        for (int node : path) result.push_back(node);

        return result;
    }
};
