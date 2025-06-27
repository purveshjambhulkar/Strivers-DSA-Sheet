class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // the steps increase by unit at a time so no need of priority_queue

        // {steps , {node , dist}}
        queue<pair<int, pair<int, int>>> q;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        q.push({0, {src, 0}});

        while (!q.empty()) {
            int step = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();

            // dont proceed further if the steps are more the k
            if (step > k) {
                continue;
            }

            for (auto n : adj[node]) {
                int adjNode = n.first;
                int adjDist = n.second;

                if (d + adjDist < dist[adjNode] && step <= k) {
                    dist[adjNode] = d + adjDist;
                    q.push({step + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == INT_MAX) {
            return -1;
        } else {
            return dist[dst];
        }
    }
};