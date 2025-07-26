// Maximum Width of Binary Tree
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, int>> q; // BFS
        q.push({root, 1}); // 1-based indexing
        
        int leftMost, rightMost;
        int max_width = 0;

        while(!q.empty()){
            int curr_idx = q.front().second;
            int curr_level_nodes = q.size(); // total non-empty nodes on current level
            leftMost = curr_idx;

            for(int i=0; i<curr_level_nodes; i++){
                auto [node, idx] = q.front();
                q.pop();

                rightMost = idx; // main task

                if(node->left) q.push({node->left, 2*idx});
                if(node->right) q.push({node->right, 2*idx+1});
            }

            max_width = max(max_width, (rightMost - leftMost +1));
        }

        return max_width;
    }
};
// Time Complexity : O(n), Space Complexity : O(n)

// Note: Use unsigned long long to avoid the integer overflow.