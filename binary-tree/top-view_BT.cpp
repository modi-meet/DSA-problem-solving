// Return a list of nodes visible from the top view of a Binary Tree
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        map<int, int> mp; // {line #, node->val}

        queue<pair<Node*, int>> q; // {node, vertical line}
        q.push({root, 0});
        
        while(!q.empty()){ // BFS
            Node* currNode = q.front().first;
            int line = q.front().second;
            q.pop();
            
            if(!mp.count(line)) mp[line] = currNode->data; // main part
            
            if(currNode->left) q.push({currNode->left, line-1}); // -1 for next left line
            if(currNode->right) q.push({currNode->right, line+1}); // +1 for next right line
            
        }
        
        for(auto &p : mp) ans.push_back(p.second);
        
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) (queue + map + ans)