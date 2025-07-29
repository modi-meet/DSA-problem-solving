// Balanced Binary Tree
// A binary tree in which the depth of the two subtrees of every node never differs by more than one.
class Solution {
    public int dfs(TreeNode node){ // finds the height of a tree
        if(node == null) return 0;

        int left = dfs(node.left);
        int right = dfs(node.right);

        if(left == -1 || right == -1) return -1;
        if(Math.abs(left-right) > 1) return -1;

        return Math.max(left, right)+1;
    }

    public boolean isBalanced(TreeNode root) {
        return dfs(root)==-1 ? false : true;
    }
}
// Time Complexity: O(N)
