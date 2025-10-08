// House Robber 3
// All houses in this place form a binary tree. 
// It will automatically contact the police if two directly-linked houses were broken into on the same night.
// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

class Solution {
    map<pair<TreeNode*, bool>, int> mp;

private:
    int solve(TreeNode* node, bool canRob){
        if(!node) return 0;

        if(mp.count({node, canRob})) return mp[{node, canRob}];

        if(canRob){
            int rob = node->val + solve(node->left, false) + solve(node->right, false);

            int notRob = solve(node->left, true) + solve(node->right, true);

            return mp[{node, canRob}] = max(rob, notRob);
        }
        else {
            // call for right and left subtree with canRob = true
            return mp[{node, canRob}] = solve(node->left, true) + solve(node->right, true);   
        }
    }

public:
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)


// Approach - 
/*
- maintain a parameter ini dfs/bfs that says whether the node can be robbed or not safely.
- when calling the child of that node, pass the ! of that.
- if taken/ robbed the current node, both the children's call cannot be robbed.
- if not tatken, both can be robbed. 

Optimize for **overlapping subproblems**.
*/