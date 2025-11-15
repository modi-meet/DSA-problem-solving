// Evaluate Division
// Given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
// Each Ai or Bi is a string that represents a single variable.

// Also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

class Solution {
    unordered_map<string, vector<pair<string, double>>> mp; // adjacency list
private:
    double dfs(string src, string dest, double pathProd, set<string>& seen) {
        seen.insert(src);
        
        if(src == dest) {
            return pathProd;
        }

        auto &v = mp[src];
        for(auto &[neigh, pathVal] : v) {
            if(!seen.count(neigh)) {
                double result = dfs(neigh, dest, pathProd*pathVal, seen);

                if(result != -1) return result;
            }
        }

        return -1;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& values, vector<vector<string>>& queries) {
       

        for(int i=0; i<eqs.size(); i++) {
            string A = eqs[i][0], B = eqs[i][1];

            mp[A].push_back({B, values[i]});
            mp[B].push_back({A, 1/values[i]});
        }

        vector<double> ans;

        for(auto &q : queries) {
            string src = q[0], dest = q[1];

            if(!mp.count(src) || !mp.count(dest)) {
                ans.push_back(-1.0);
                continue;
            } 

            set<string> seen;

            double prod = dfs(src, dest, 1.0, seen);
            ans.push_back(prod);
        }

        return ans;
    }
};
// Time: O(Q×(V+E)) where Q = queries, V = variables, E = equations. Each query does a DFS.
// Space: O(V+E) for the graph + O(V) for the visited set per query.