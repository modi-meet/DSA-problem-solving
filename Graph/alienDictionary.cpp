// Alien Dictionary
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        
        unordered_set<char> set;
         // Step 1: collect all unique characters
        for(int i=0; i<n; i++){
            for(auto ch : words[i]) set.insert(ch);
        }
        
        int V = set.size();
        vector<vector<int>> adj(26); // for each letter
        
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            int len = min(s1.length(), s2.length());
            bool found = false;
            for(int s=0; s<len; s++){
                if(s1[s] != s2[s]) {
                    adj[s1[s] - 'a'].push_back(s2[s] - 'a');
                    found = true;
                    break;
                }
            }
            
            if(!found && s1.size() > s2.size()) return "";
        }
        
        vector<int> inDegree(26);
        for(int u=0; u<26; u++){
            for(auto v : adj[u]){
                inDegree[v]++;
            }
        }
        
        queue<int> q;
        for(int node=0; node<26; node++){
            if(set.count(node + 'a') && inDegree[node] == 0) // Important
                q.push(node);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto neighbour : adj[node]){
                inDegree[neighbour]--;
                
                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }        
        
        if(topo.size() != V) return "";
        
        string order = "";
        for(auto ch : topo) order += (char)(ch + 'a');
        
        return order;
    }
};