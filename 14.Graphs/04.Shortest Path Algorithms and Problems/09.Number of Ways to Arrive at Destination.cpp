class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> dist(n, numeric_limits<long long>::max());
        dist[0] = 0;

        long long MOD = 1e9 + 7;
        vector<long long> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0LL, 0});

        while (!pq.empty()) {
            long long current_time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (current_time > dist[node]) {
                continue;
            }

            for (auto& neighbor_pair : adj[node]) {
                int adjNode = neighbor_pair.first;
                int edge_weight = neighbor_pair.second;

                long long new_path_time = current_time + edge_weight;

                if (new_path_time < dist[adjNode]) {
                    dist[adjNode] = new_path_time;
                    ways[adjNode] = ways[node];
                    pq.push({new_path_time, adjNode});
                } else if (new_path_time == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return static_cast<int>(ways[n - 1]);
    }
};