# Graphs

## What is a Graph?

A **graph** is a set of **nodes (vertices)** connected by **edges**.

- **Undirected Graph** → edges don’t have direction (like a friendship network).  
- **Directed Graph** → edges have direction (like Instagram follow).  
- **Weighted Graph** → edges have a cost/weight (like distances on Google Maps).  
- **Unweighted Graph** → all edges are equal.  

**Graphs can be represented as:**
- **Adjacency List** → efficient for sparse graphs.  
- **Adjacency Matrix** → good for dense graphs.  

---

### Traversal
- **BFS (Breadth First Search)** – explore layer by layer.  
- **DFS (Depth First Search)** – go as deep as possible, then backtrack.  

### Shortest Path
- **BFS** → for unweighted graphs.  
- **Dijkstra** → for positive weights.  
- **Bellman-Ford** → works with negative weights.  
- **Floyd-Warshall** → all-pairs shortest path.  

### Connected Components
- Finding separate **"islands"** or clusters in a graph.  

---

## How to Identify Graph Problems?

👉 Whenever you see:

- **“Grid/Matrix problems”** → (01-matrix, number of islands, rotting oranges) → Usually **BFS/DFS**.  
- **“Shortest/Minimum”** → Think **BFS/Dijkstra/Bellman-Ford**.  
- **“Check if possible/valid”** → Often **Topological sort, cycle detection, or bipartite check**.  
- **“Connectivity”** → **Union-Find (DSU)** or **DFS**.  
- **“Min/Max edges”** → **Kruskal’s/Prim’s (MST problems)**.  

---

## Common Graph Problem Patterns

### 1. Traversal & Flood Fill
- `BFS-traversal.cpp`  
- `DFS-traversal.cpp`  
- `floodFill-Algo.cpp`  

### 2. Grid-Based (Matrix as Graph)
- `01matrix.cpp` / `nearest1distance.cpp`  
- `numberOfIslands.cpp`  
- `distinctIslands.cpp`  
- `rottingOranges.cpp`  
- `replaceOwithX.cpp`  
- `pacificAtlantic.cpp`  
- `numOfEnclaves.cpp`  

**Trick:** Treat each cell as a **node**, and up/down/left/right as **edges**.

### 3. Shortest Path Problems
- `shortestPathUG.cpp`  
- `Dijkstra.cpp`  
- `bellman_ford-algo.cpp`  
- `floyd_warshall-Algo.cpp`  
- `BinaryMatrixPath.cpp`  
- `minMultiplications.cpp`  
- `KstopsFlights.cpp`  
- `waysToReachDestination.cpp`  

### 4. Graph Properties
- Detect Cycle → `detectCycle-BFS.cpp`, `detectCycle-DFS.cpp`, `detectCycle_Directed-BFS.cpp`, `detectCycle_Directed-DFS.cpp`  
- `bipartite-graph.cpp`  
- `safeStates.cpp`  

### 5. Topological Sorting / Dependencies
- `alienDictionary.cpp`  
- `wordLadder.cpp` / `wordLadder-2.cpp`  

### 6. Bridges, SCC & Advanced Graphs
- `bridges.cpp`  
- `kosaraju-Algo.cpp`  
- `city.cpp`  

### 7. Minimum Spanning Tree (MST)
- `krushkals-Algo.cpp`  
- `prims-Algo.cpp`  

---

## Disjoint Set Union (DSU) 😎

Sometimes we don’t want to actually **traverse** the graph but just need to know:

- Are two nodes connected?  
- What’s the size of the component?  
- How many groups/components are there?  

That’s where **DSU (Union-Find)** comes in.

### Core Ideas
- **Find** → Check which set (parent) a node belongs to.  
- **Union** → Merge two sets.  
- **Path Compression** → Makes future lookups faster.  
- **Union by Rank/Size** → Keeps tree shallow.  

### Where DSU Helps?
- **Kruskal’s Algorithm (MST)**.  
- **Detecting cycles in undirected graphs.**  
- **Counting connected components.**  
- **Problems like removeStones (DSU).**

- ## When to Use DSU?
- Detecting **cycles** in undirected graphs.  
- Finding **connected components**.  
- **MST (Kruskal’s Algorithm)** → picking edges while ensuring no cycle.  
- Problems where **merging/grouping** is needed.

---

## 🌟 Pro Tips for DSU
- Always start with a **parent array** (each node is its own parent).  
- Implement **path compression + union by rank/size** → this makes DSU almost **O(1)** per operation.  
- Think DSU when:
  - The problem says **“merge”, “group”, “connect”, “components”**.  
  - You need to ensure **no cycles** (like Kruskal’s MST).  
  - You need to count groups after several union operations.  

---


**Related files:**   
- - `DSU-Basics.cpp`  
- `connectnetwork.cpp`  
- `islands2.cpp`  
- `mergeIsland.cpp`  
- `mergeMail.cpp`  
- `provinces.cpp`  
- `removeStones.cpp`
- `krushkals-Algo.cpp`

---