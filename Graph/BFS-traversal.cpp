// Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. 
// Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list,
// Return an array containing the BFS traversal of the graph.

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> ans;
        
        vector<bool> seen(n, false);
        queue<int> q;
        q.push(0); // 0th index graph node
        seen[0] = true; // mark 0th idx as seen
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto nod : adj[node]){
                if(seen[nod] == false){
                    q.push(nod);
                    seen[nod] = true;
                }
            }
        }
        
        return ans;
    }
};

// Time Complexity : O(N) + O(2*E) (IMPORTANT)
// Space Complexity: O(3*N) ~ O(N)