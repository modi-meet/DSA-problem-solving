// Given the root of a Binary Search Tree,
// return the minimum difference between the values of any two different nodes in the tree.
class Solution {
public:
    int minDiff = INT_MAX, prev = -1;
    int minDiffInBST(TreeNode* root) {
        if(root->left) minDiffInBST(root->left);
        
        if(prev != -1) minDiff = min(minDiff, abs(prev - root->val));
        prev = root->val;

        if(root->left) minDiffInBST(root->left);

        return minDiff;
    }
};
// TIME COMPLEXITY : O(n)
// Space complexity : O(H) (recursion stack)

/*
Explanation

To find the minimum absolute difference betweeen any two node of BST,
    - traverse the BST inorder
    - maintain prev variable that store the value of parent node
    - calculate the min_diff for every node, diff of root->val and prev value

And, that's it!
*/