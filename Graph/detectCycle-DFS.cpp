class Solution {
private:
    bool detect(int i, int parent, vector<vector<int>>& adj, vector<int>& seen){ //dfs
        seen[i] = 1;
            
        for(auto node : adj[i]){
            if(seen[node] == 0) { // not seen
                seen[node] = 1;
                if(detect(node, i, adj, seen)) return true;
            }
            else if(node != parent){ // seen, parents are diffent; cycle detected
                return true; 
            } 
        }
        
        return false;
    }
    
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); // adjacency List
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> seen (V, 0);
        
        for(int i=0; i<V; i++){
            if(!seen[i]){
                if(detect(i, -1, adj, seen)) return true;
            }
        }
        return false;
    }
};
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

// We have a cycle if we arrive at the same cell from multiple directions during DFS.