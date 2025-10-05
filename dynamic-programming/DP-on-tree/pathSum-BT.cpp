// Given a binary tree, find the maximum path sum. 
// The path may start and end at any node in the tree.

class Solution {
private:
    int solve(Node* node, int& res){
        // Base case
        if(node == NULL) return 0;
        
        // Hypothesis
        int left = solve(node->left, res);
        int right = solve(node->right, res);
        
        // Only include positive contributions
        left = max(0, left);
        right = max(0, right);
        
        // induction
        int temp = max(node->data, max(left, right) + node->data); // case 1
        int ans = node->data + left + right; // case 2
        res = max(res, ans);
        
        return temp;
    }
    
public:
    int findMaxSum(Node *root) {
        // code here
        int res = INT_MIN;
        solve(root, res);
        
        return res;
        
    }
};
// Time Complexity: O(n)
// Space Complexity: O(h)