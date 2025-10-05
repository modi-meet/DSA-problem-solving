// Given the root of a binary tree, find the diameter of the binary tree.
// Diameter - Maximum path distance between any two leaf node

class Solution {
private:
    int solve(Node* node, int& res){
        // Base case
        if(node == NULL) return 0;
        // Hypothesis
        int left = solve(node->left, res);
        int right = solve(node->right, res);
        
        // induction
        int temp = 1 + max(left, right); // case 1
        int ans = 1 + left + right; // case 2
        res = max(res, ans);
        
        return temp;
    }
    
public:
    int diameter(Node* root) {
        int res = 0;
        solve(root, res);
        
        return res-1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(h)