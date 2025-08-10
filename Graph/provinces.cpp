// Numner of Provinces
// In a whole graph, how many graphs individual froups of graphs are there

// DFS (Adj List) Appraoch
class Solution {
private:
    void dfs(int stNode, vector<bool>& seen, vector<vector<int>>& adj) {
        seen[stNode] = true;

        for(auto node : adj[stNode]){
            if(seen[node] == false) {
                dfs(node, seen, adj);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // adjacency list

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1) { // i, j - two nodes connected
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int prov = 0;
        vector<bool> seen(n, false);

        for(int i=0; i<n; i++){
            if(!seen[i]) { // if the node is not visited in dfs, that means it was broken somewhere
                prov++;
                dfs(i, seen, adj);
            }
        }

        return prov;
    }
};
// Time Complexity: O(N) + O(V + 2*E)
// Space Complexity: O(N)

// BFS(Adj List) Approach
class Solution {
private:
    void bfs(int stNode, vector<bool>& seen, vector<vector<int>>& adj) {
        seen[stNode] = true;

        queue<int> q;
        q.push(stNode);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbour : adj[node]){
                if(!seen[neighbour]){
                    q.push(neighbour);
                    seen[neighbour] = true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n); // adjacency list

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1) { // i, j - two nodes connected
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int prov = 0;
        vector<bool> seen(n, false);

        for(int i=0; i<n; i++){
            if(!seen[i]) { // if the node is not visited previously; new province node found
                prov++;
                bfs(i, seen, adj);
            }
        }

        return prov;
    }
};
// Time Complexity: O(N) + O(V + 2*E)
// Space Complexity: O(N)