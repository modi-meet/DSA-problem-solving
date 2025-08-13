// Is Graph Bipartite?

// DFS
class Solution {
private:
    bool dfs(int st, vector<vector<int>>& graph, vector<int>& color){

        for(auto neighbour : graph[st]){
            if(color[neighbour] == -1){ // not yet colored
                color[neighbour] = !color[st];
                if (dfs(neighbour, graph, color) == false) return false;
            } 
            else { // neighbour is colored already
                if(color[neighbour] == color[st]) return false;
            }
        }
        
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , -1); // mark all not coloured

        for(int i=0; i<n; i++){ // loop because graph may have multiple components
            if(color[i] == -1){
                if(dfs(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};
// Time Complexity:  O(V + E)
// Space Complexity: O(V)

// BFS
class Solution {
private:
    bool bfs(int st, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(st);
        color[st] = 0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto neighbour : graph[node]){
                if(color[neighbour] == -1){ // not yet colored
                    color[neighbour] = !color[node];
                    q.push(neighbour);
                } 
                else { // neighbour is colored already
                    if(color[neighbour] == color[node]) return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n , -1); // mark all not coloured

        for(int i=0; i<n; i++){ // loop because graph may have multiple components
            if(color[i] == -1){
                if(bfs(i, graph, color) == false) return false;
            }
        }
        return true;
    }
};
// Time Complexity:  O(V + E)
// Space Complexity: O(V)