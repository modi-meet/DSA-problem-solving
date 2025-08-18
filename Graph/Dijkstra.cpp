// Dijkstra's Algorithm

// Using Priority Queue (min_heap)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto ed : edges){
            int u = ed[0], v = ed[1], w = ed[2];
            
            adj[u].push_back({v, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // { dist, node} 
        
        vector<int> dist(V, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            for(auto [adjNode, adjWt] : adj[node]) {
                
                if(d + adjWt < dist[adjNode]) {
                    pq.push({d + adjWt, adjNode});
                    dist[adjNode] = d+adjWt;
                }
            }
        }
        return dist;
    }
};
// Time Complexity: O((V + E) * log V)
// Space Complexity: O(V + E)

// Using Set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto ed : edges){
            int u = ed[0], v = ed[1], w = ed[2];
            
            adj[u].push_back({v, w});
        }

        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);

        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()){
            auto [d, node] = *st.begin();
            st.erase({d, node});

            for(auto [adjNode, adjWt] : adj[node]){
                if(d + adjWt < dist[adjNode]){
                    st.insert({d + adjWt, adjNode});

                    if(dist[adjNode] != INT_MAX) st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = d+adjWt;                   
                }
            }
        }
        return dist;
    }
};
// Time Complexity: O((V + E) * log V)
// Space Complexity: O(V + E)

// The Graph is connected and doesn't contain any negative weight edge.
// For Dijkstra's Algorithm -ve weights will lead to infinite loop.