class Solution {
private:
    bool detect(int i, vector<vector<int>>& adj, vector<int>& seen){
        seen[i] = 1;
            
        // stores : {current node, parent node}
        queue<pair<int,int>> q;
        q.push({i, -1});
        
        while(!q.empty()){
            auto [curr, parent] = q.front(); // {curr node, parent node}
            q.pop();
            
            for(auto node : adj[curr]){
                if(seen[node] == 0) {
                    seen[node] = 1;
                    q.push({node, curr});
                }
                else if(node != parent){ // cycle detected
                    return true; 
                } 
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
                if(detect(i, adj, seen)) return true;
            }
        }
        return false;
    }
};

// We have a cycle if we arrive at the same cell from multiple directions during BFS.