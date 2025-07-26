//  Find the Bottom Left Tree Value

// BFS Solution
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return -1;

        queue<TreeNode*> q; // BFS
        q.push(root);
        int bottomLeft;
        
        while(!q.empty()){
            int size = q.size();

            bottomLeft = q.front()->val; // leftmost node of current level

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return bottomLeft;
    }
};
// Time Complexity: O(n), Space Complexity: O(n)(queue)

// DFS Solution
class Solution {
    int maxDepth = -1, bottomLeft;

    void solve(TreeNode* node, int currDepth){
        if(node == NULL) return;

        if(currDepth > maxDepth){ // new level; increase max_depth & update bottom-left value
            maxDepth = currDepth;
            bottomLeft = node->val;
        }

        solve(node->left, currDepth+1);
        solve(node->right, currDepth+1);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return -1;
        solve(root, 0);

        return bottomLeft;
    }
};
// Time Complexity: O(n), Space Complexity: O(H) - height of the tree (System stack) 