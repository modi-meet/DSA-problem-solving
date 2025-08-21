// Bellman-Ford Algorithm
// Implimented to find the shortest path(distance) between nodes from a source.
// Especially applicable, when the graph has -ve weights or has negative cycles.

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Bellman Ford algorithms (repeat till N-1 times)
        for(int i=0; i<V; i++) {
            for(auto &ed : edges) {
                int u = ed[0], v = ed[1], wt = ed[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Detect a negative cycle (by iterating at Nth iteration)
        for(auto &ed : edges) {
            int u = ed[0], v = ed[1], w = ed[2];
                
            if(dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};
// Time Complexity : O(V*E)
// Space Complexity : O(V)