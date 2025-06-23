class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : graph[u]) {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            safe.push_back(temp);

            for (int n : revAdj[temp]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};