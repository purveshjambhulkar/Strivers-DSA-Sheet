// problem link - https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1


int find(int par[], int x) {
        // If 'x' is its own parent, it means 'x' is the root of its set.
        if (par[x] == x) {
            return x;
        }
        // Otherwise, recursively find the root and perform path compression:
        // Make 'x' directly point to the ultimate root found.
        return par[x] = find(par, par[x]);
    }

    // Function to perform the union of two sets containing 'x' and 'z'.
    // The problem specifies: parent of 'z' will become the parent of 'x'.
    void unionSet(int par[], int x, int z) {
        // Find the ultimate parent (root) of 'x'
        int rootX = find(par, x);
        // Find the ultimate parent (root) of 'z'
        int rootZ = find(par, z);

        // If 'x' and 'z' are already in the same set (i.e., their roots are the same),
        // no union operation is needed.
        if (rootX != rootZ) {
            // As per problem statement: "parent of z will become the parent of x"
            // This means the root of the set containing 'x' will now point to
            // the root of the set containing 'z'.
            par[rootX] = rootZ;
        }
    }