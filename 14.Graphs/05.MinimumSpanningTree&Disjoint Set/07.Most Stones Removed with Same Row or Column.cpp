class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Total number of nodes needed in DSU: maxRow + maxCol + 2
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, bool> stoneNodes;

        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;

            ds.unionByRank(rowNode, colNode);
            stoneNodes[rowNode] = true;
            stoneNodes[colNode] = true;
        }

        int numComponents = 0;
        for (auto& node : stoneNodes) {
            if (ds.findParent(node.first) == node.first) {
                numComponents++;
            }
        }

        return n - numComponents;
    }
};
