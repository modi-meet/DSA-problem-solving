// Given a tree node, Return the Diameter of Binary Tree
// Diameter is defined as the length of the longest path between any two nodes in a tree.
class Solution {
    int maxDiam = 0;

    public int dfs(TreeNode root){
        if(root == null) return 0;

        int left = dfs(root.left);
        int right = dfs(root.right);

        maxDiam = Math.max(maxDiam, left+right);

        return Math.max(left, right)+1;
    }

    public int diameterOfBinaryTree(TreeNode root) {
        dfs(root);

        return maxDiam;
    }
}
// Time Complexity: O(n)