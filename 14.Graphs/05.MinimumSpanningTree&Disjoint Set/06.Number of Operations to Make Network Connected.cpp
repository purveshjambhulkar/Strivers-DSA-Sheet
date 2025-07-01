class DisjointSet {

public:
    vector<int> parent, rank;
    int extraEdges;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        // initialize the parent of each node with the node itself
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }

        extraEdges = 0;
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        // path compression
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int node1, int node2) {

        int node1Parent = findParent(node1);
        int node2Parent = findParent(node2);

        if (node1Parent == node2Parent) {
            // extra node found
            extraEdges++;
            return;
        }

        int rankNode1 = rank[node1Parent];
        int rankNode2 = rank[node2Parent];

        if (rankNode1 > rankNode2) {
            parent[node2Parent] = node1Parent;
        } else if (rankNode2 > rankNode1) {
            parent[node1Parent] = node2Parent;
        } else {
            parent[node1Parent] = node2Parent;
            rank[node2Parent]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        // traverse all the edges and add in DSU
        //  while traversing keep a track on the extra edges in all components
        //  then simply check whether the no of extra edges is greater than of
        //  equal to no of components ,if so the return ans else -1
        // to connect n components we will require n - 1 edges

        DisjointSet Ds(n);

        // Step1 - traverse the connections and apply union of each of them

        for (auto conn : connections) {

            int u = conn[0];
            int v = conn[1];

            Ds.unionByRank(u, v);
        }

        // to find the no of components
        // here we can use a set or unordered map
        // by using map will keep the track of the unique parent
        // here we are using set

        unordered_set<int> set;

        for (int i = 0; i < n; i++) {

            set.insert(Ds.findParent(i));
        }

        if (set.size() - 1 <= Ds.extraEdges) {
            return set.size() - 1;
        } else {
            return -1;
        }
    }
};