// Binary Tree Right Size View
class Solution {
    private void solve(TreeNode root, int level, List<Integer> ans){
        if(root == null) return;

        if(level == ans.size()) ans.add(root.val);

        solve(root.right, level+1, ans);
        solve(root.left, level+1, ans);
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        solve(root, 0, ans);

        return ans;
    }
}
// Time Complexity: O(n)
// Space Complexity: O(H)+O(H) (recursion call + ans array)