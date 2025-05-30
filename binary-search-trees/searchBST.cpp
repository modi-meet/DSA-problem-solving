/**
 * binary tree node defined as:
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:x
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;

        if(val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

// Time complexity: O(log n) or O(height of the tree)

/* 
Explanation
- Since element to left are small than root and elements to right are greater than root in BST we use same property to traverse and check
- if root == val , means we found the root, retrun it.
- if val < root.val . means we have to traverse only to left-subtree, discard right part.
- else val > root.val . means we have to traverse only to right-subtree, discard left part.
*/