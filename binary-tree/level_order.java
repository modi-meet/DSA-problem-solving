// Binary Tree Level Order Traversal
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null) return ans;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while(!q.isEmpty()){
            int size = q.size();

            List<Integer> temp = new ArrayList<>();
            for(int i=0; i<size; i++){
                TreeNode node = q.poll();

                if(node != null) temp.add(node.val);

                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            ans.add(temp);
        }
        return ans;
    }
}
// Time Complexity: O(N)
// Space Complexity: O(N) (queue)