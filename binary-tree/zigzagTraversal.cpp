// Binary Tree Zigzag Level Order Traversal
// for 1st level, from left to right, then right to left for the next level and so on.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int curr_level = 0;

        while(!q.empty()){
            curr_level++;
            int size = q.size();

            vector<int> temp;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();                

                if(node != NULL) temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(curr_level % 2 == 0) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N) (queue+temp array)