//  Minimum Spanning Tree (MST)
// Prim's Algoritihm


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto&ed : edges){
            adj[ed[0]].push_back({ed[1], ed[2]});
            adj[ed[1]].push_back({ed[0], ed[2]});
        }
        
        vector<int> seen(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {wt, node}
        pq.push({0, 0});
        
        int sum = 0;
        
        // O(E)
        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();
            
            if(seen[node]) continue;
            seen[node] = 1;
            sum += w;
            
            for(auto [adjNode, adjWt] : adj[node]) {
                if(!seen[adjNode]) pq.push({adjWt, adjNode});
            }
        }
        return sum;
    }
};
// Time Complexity: O(E*logE + E*logE)
// Space Complexity: O(V+E)