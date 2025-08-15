// Topological Sort
// a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

// DFS
class Solution {
private: 
    void dfs(int node, vector<vector<int>>& adj, stack<int>& st, vector<int>& seen){
        seen[node] = 1;
        
        for(auto neighbour : adj[node]){
            if(!seen[neighbour]){
                dfs(neighbour, adj, st, seen);
            }
        }
        
        st.push(node); // push when no further calls can be made from current node
    }
    
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj (V);
        
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
        }
        
        vector<int> seen(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!seen[i]) dfs(i, adj, st, seen);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
// Time Complexity: O(V + E)
// Space Complexity: O(V)

// BFS - Kahn's Algorithm
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj (V);
        
        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
        }
        
        vector<int> seen(V, 0);
        vector<int> inDegree(V, 0);
        
        for(int i=0; i<V; i++){
            for(int deg : adj[i]) inDegree[deg]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            seen[node] = 1;
            
            for(auto neighbour : adj[node]){
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }
        
        return ans;
    }
};

// Topological Sort:
// - Only applicable on DAG (Directed Asyclic Graph)