// Detect a cycle in a directed Graph

class Solution {
public:
    vector<int> isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> seen(V, 0);
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++){
            for(int deg : adj[i]) inDegree[deg]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        int topoSize = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // ans.push_back(node);
            topoSize++;
            seen[node] = 1;
            
            for(auto neighbour : adj[node]){
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }
        
        if(topoSize == V) return false; // No cycle
        return true;
    }
};