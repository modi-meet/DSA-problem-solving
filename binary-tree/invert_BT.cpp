// Invert Binary, Given the root of a binary tree, invert the tree, and return its root.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode* temp = root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                swap(node->left, node->right);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return temp;
    }
};