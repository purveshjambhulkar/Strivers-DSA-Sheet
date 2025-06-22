# 📘 Graph Theory Notes

---

## **1. What is a Graph?**

A **graph** is a non-linear data structure consisting of:
- **Vertices (nodes)** — entities in the graph.
- **Edges (links)** — connections between nodes.

Graphs can represent real-world systems like:
- Social networks
- Road maps
- Network topologies
- Task scheduling

---

## **2. Types of Graphs**

### **Based on Direction:**
- **Undirected Graph**: Edges have no direction.  
  Example: `A -- B` means A is connected to B and vice versa.
  
- **Directed Graph (Digraph)**: Edges have direction.  
  Example: `A → B` means A points to B but not necessarily the other way.

### **Based on Weight:**
- **Weighted Graph**: Each edge has a weight (cost/distance).
- **Unweighted Graph**: All edges are treated equally.

### **Based on Edge Structure:**
- **Cyclic Graph**: Contains at least one cycle.
- **Acyclic Graph**: No cycles.

### **Based on Connectivity:**
- **Connected Graph**: There is a path between every pair of vertices.
- **Disconnected Graph**: Some vertices cannot be reached from others.

### **Special Graphs:**
- **Tree**: A connected acyclic graph.
- **DAG (Directed Acyclic Graph)**: A directed graph with no cycles.

---

## **3. Graph Representation in C++**

### **Adjacency Matrix:**
- 2D vector of size `V x V` (V = number of vertices)
- `matrix[i][j] = 1` if edge exists between i and j

```cpp
int V = 5;
vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
adjMatrix[0][1] = 1;
adjMatrix[1][0] = 1; // for undirected
```

**Pros**: Easy edge checks  
**Cons**: Space: O(V²), inefficient for sparse graphs

---

### **Adjacency List:**
- Vector of lists or vectors, where `adj[i]` stores neighbors of node `i`

```cpp
int V = 5;
vector<vector<int>> adjList(V);
adjList[0].push_back(1);
adjList[1].push_back(0); // for undirected
```

**Pros**: Space efficient, O(V + E)  
**Cons**: Edge lookup slower than matrix

---

## **4. BFS (Breadth-First Search)**

- Traverses level by level (like layers)
- Uses a **queue**
- Good for finding **shortest path in unweighted graphs**

```cpp
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V)

---

## **5. DFS (Depth-First Search)**

- Explores as deep as possible before backtracking
- Uses **recursion** or **stack**

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
```

**Time Complexity**: O(V + E)  
**Space Complexity**: O(V) (due to recursion stack)

---

## **6. BFS vs DFS**

| Feature         | BFS                       | DFS                         |
|----------------|---------------------------|-----------------------------|
| Data Structure | Queue                     | Stack / Recursion           |
| Space Usage    | More (due to queue)       | Less (in iterative), recursion stack |
| Path Finding   | Finds shortest path       | May not find shortest path  |
| Usage          | Shortest path, Level-order| Cycle detection, Topo sort  |

---

## **7. When to Use What?**

- **BFS**: Shortest path in unweighted graph, nearest node discovery
- **DFS**: Cycle detection, topological sort, connected components

---

## 📌 Bonus Tip:

### For Undirected Graph Input as Edges:

```cpp
vector<vector<int>> adj(V);
for (auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u); // because it's undirected
}
```

---

