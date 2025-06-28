class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;

        if(p->val < root->val && q->val < root->val) // both are less; go to left subtree
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val) // both are larger; go to right subtree
            return lowestCommonAncestor(root->right, p, q);
        else     // both are in diff subtrees; found the ancestor
            return root;       
    }   
};
// Time Complexity : O(H) (height of the tree)
// Space Complexity  : O(1) auxiliary + O(H) (recursion call stack)