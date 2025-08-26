// Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. 
// Note that even if two accounts have the same name, they may belong to different people as people could have the same name. 
// A person can have any number of accounts initially, but all of their accounts defin

class Solution {
public:
    
    // DSU class
    class DisjointSet {
        vector<int> rank;
    public:
        vector<int> parent;
        
        DisjointSet(int Size) {
            parent = vector<int> (Size);
            rank = vector<int> (Size, 0);

            for(int i=0; i<Size; i++) parent[i] = i; // initially mark node as their own parent
        }

        int ultimateParent(int u) {
            if(u == parent[u]) return u;

            return parent[u] = ultimateParent(parent[u]); // store the new parent (for path compression)
        }

        void unite(int u, int v) { // by Rank
            int ultiParent_u = ultimateParent(u);
            int ultiParent_v = ultimateParent(v);

            if(ultiParent_u == ultiParent_v) {
                return; // both belongs to same set; cycle detected
            }
            if(rank[ultiParent_u] < rank[ultiParent_v]) { // parent will be the one with higher rank
                parent[ultiParent_u] = ultiParent_v; // update new parent
            }
            else if(rank[ultiParent_v] < rank[ultiParent_u]) {
                parent[ultiParent_v] = ultiParent_u; // update new parent
            } 
            else { // both has same rank; join v to u
                parent[ultiParent_v] = ultiParent_u;
                rank[ultiParent_u]++; // update the rank of parent
            }   
        }
    };
        
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> mp; // <mails, idx>

        DisjointSet ds(n);

        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                
                if(!mp.count(mail)) {
                    mp[mail] = i; 
                } else { // else, mail already has the owner; merge them
                    ds.unite(mp[mail], i);
                } 
            }
        }

        vector<vector<string>> mergedMail(n);
        
        for(auto [mail, par] : mp){
            int ULpar = ds.ultimateParent(par);
            
            mergedMail[ULpar].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue; // got merged, skip.

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto &s : mergedMail[i]) temp.push_back(s);

            ans.push_back(temp);
        }
        return ans;
    }
};

/*
// tasks to perform :
1. assign correct parent & merge same ultimate parents
2. make final - name vs their all accounts list
3. sort the accounts
4. return final answer
*/

// Time Complexity: O(M * 4alpha) + O(M * 4aplha) + O(M*logM + M) (M - total number of emails overall)
// Space Complexity: O(n + M)