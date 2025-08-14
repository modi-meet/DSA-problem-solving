// Detect a cycle in a directed Graph

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& seen, vector<int>& pathSeen){
        seen[node] = 1;
        pathSeen[node] = 1; 
        
        for(auto neighbour : graph[node]){
            if(seen[neighbour]){
                // already seen; no need to traverse just check if seen in the path or not
                if(pathSeen[neighbour] == 1) return true;
            } 
            else { // not seen yet
                if(dfs(neighbour, graph, seen, pathSeen) == true) return true;
            }
        }   
        
        pathSeen[node] = 0; // remove from current path; backtrack
        
        return false;
    }
    
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> seen(V, 0); // nodes are visited or not
        vector<int> pathSeen(V, 0); // nodes are visited in current path or not
        
        for(int i=0; i<V; i++){
            if(!seen[i]) {
                if(dfs(i, graph, seen, pathSeen) == true) return true;
            }
        }
        
        return false;
    }
};
// Time Complexity:  O(V + E)
// Space Complexity: O(V)

// While traversing if we find a node which was seen already in curr Path (already seen); That means we detected a cycle.