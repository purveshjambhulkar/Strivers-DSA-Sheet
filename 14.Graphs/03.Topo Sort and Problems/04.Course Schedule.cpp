class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);
        }

        // find indegree
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto n : adj[i]) {
                indegree[n]++;
            }
        }

        // add indegree 0 nodes in queue
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // topo sort
        vector<int> topo;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            topo.push_back(temp);

            for (auto n : adj[temp]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

          
        if(topo.size() == numCourses){
            return true;
        }else{
            return false;
        }
        


    }
};