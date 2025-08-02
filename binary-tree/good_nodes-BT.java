// Given a binary tree root, a node in the tree is good:
// - if in the path from root to node, there are no nodes with a value greater than current node.
// Return the number of good nodes in the binary tree.
class Solution {
    int good_nodes = 0;
    public void dfs(TreeNode root, int maxSoFar){
        if(root == null) return;

        if(root.val >= maxSoFar) good_nodes++;

        dfs(root.left, Math.max(maxSoFar, root.val));
        dfs(root.right, Math.max(maxSoFar, root.val));
    }

    public int goodNodes(TreeNode root) {
        dfs(root, Integer.MIN_VALUE);

        return good_nodes;
    }
}
// Time Complexity: O(N)
// Space Complexity: O(H)
