// Maximum Depth of Binary Tree
class Solution {
public:
    int Depth(TreeNode* root, int depth){
        if(root == NULL) return depth;
        
        int leftDepth = Depth(root->left, depth+1);
        int rightDepth = Depth(root->right, depth+1);

        return max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode* root) {
        return Depth(root, 0);
    }
};
//Time Complexity: O(n)