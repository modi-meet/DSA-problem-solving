// Given the root node of a binary search tree, 
// Return the sum of values of all nodes with a value in the range [low, high].

class Solution {
public:    
    int rangeSumBST(TreeNode* root, int low, int high) {
        // BRUTE APPROACH
        if(root == NULL) return 0;

        int sum = 0;
        if(root->val >= low && root->val <= high) sum += root->val;

        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);

        return sum;
    }
};
// Time Complexity : O(n) (n = number of nodes)
// Space Complexity : O(h) recursive stack (h = height of tree)

class Solution {
public:    
    int rangeSumBST(TreeNode* root, int low, int high) {
        // BETTER APPROACH
        if(root == NULL) return 0;

        if(root->val < low)
            return rangeSumBST(root->right, low, high);
        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        // root->val is withhin [low, high]
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
// TC: O(h) in (balanced BST), O(n) in worst case
// SC: O(h)