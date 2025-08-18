// Shortest Path in Weighted undirected graph
// Find the shortest weight path between the vertex 1 and the vertex n, Return a list of integers consist of the nodes on that path. 
// If no path exists, then return a list containing a single element -1.

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto &ed : edges){
            adj[ed[0]].push_back({ed[1], ed[2]});
            adj[ed[1]].push_back({ed[0], ed[2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1); // parent node from where we came from via shortest distance
        
        for(int i=1; i<=n; i++) parent[i] = i;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop(); // log(pq size)
 
            for(auto [adjNode, adjWt] : adj[node]){
                if(d + adjWt < dist[adjNode]) {
                    parent[adjNode] = node;
                    
                    pq.push({d + adjWt, adjNode});
                    dist[adjNode] = d + adjWt;
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
         
        vector<int> ans;
        int node = n;
        
        while(parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(node); // node - 1
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// TC : O(E * log(V))
// SC : O(V + E)

// Dijkstra's Algo is useful, (take source node as 1)
// But, it can only give the shortest distances (dist array)
// We need a track of which node helped us find the shortest distance, for each node.