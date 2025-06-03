//Kth Smallest Element in a BST, k is 1-indexed

//BRUTE APPROACH (using recursion & extra space)

//TIME COMPLEXITY: O(n)
//Space compelexity : O(n) (for inorder array)
class Solution {
public: 
  vector<int> inorder;

  void inorderBST (TreeNode* root){
    if(root == NULL) return;

    inorderBST(root->left);
    if(root != NULL) inorder.push_back(root->val);
    inorderBST(root->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    inorderBST(root);

    for(int i=0; i<inorder.size(); i++){
        if(i == k-1) return inorder[i];
    }

    return -1;
  }
};


//OPTIMAL APPROACH (using recursion & no extra space)

//TIME COMPLEXITY: O(H + K) or O(N) (worst case)
//Space compelexity : O(H) (H - height of the tree) (for recursion)
class Solution {
public: 
    int level = 0, ans = -1;

  void helper (TreeNode* root, int k){
    if(root == NULL) return;

    // Left
    helper(root->left,  k);

    // Node
    level++;

    if(level == k) {
        ans = root->val;
        return;
    }

    // Right
    helper(root->right, k);
  }

  int kthSmallest(TreeNode* root, int k) {
    helper(root, k);

    return ans;
  }
};


//-------Iterative Approach---------
// stack-based

//TIME COMPLEXITY: O(H + K) or O(N) (worst case)
//Space compelexity : O(n)
class Solution {
    int ans = -1;

  void helper(TreeNode? root, int k){
    int limit = 0;
    List<TreeNode?> st = [];

    while(root != null || st.isNotEmpty){
        while(root != null){ //go to extreme left
            st.add(root);
            root = root.left;
        } //L

        root = st.removeLast();
        //N
        limit++;
        if(limit == k) {
            ans = root!.val; 
            return;
        }
        //R
        root = root!.right;
    }
  }

  int kthSmallest(TreeNode? root, int k) {
    helper(root, k);
    
    return ans;
  }
}

/* 
*******Explanation*******
 
---------BRUTE APPROACH----------
in BST, inorder traversal array will be,
    - Inorder is Left-node-Right
so, the inorder will give the sorted array for the given BST.
    - we can store the array and return kth element and that will be the answer.
This is the brute way to solve this.

---------BETTER APPROACH----------
Instead of using extra space to store inorder array,
    - maintain a variable ('level')

Inorder traversal is Left-node-Right:
    - while backtracking from Left, means when we have reached the leftmost node and are now returning to its parent (the current node)as mentioned in inorder,
    - we will increase 'level'.

Whenever the 'level' becomes same as 'k', that will be the kth smallest value.

--------Iterative Approach---------
For iterative approach, go to the extreme left of the BST till the leaf node,
 - once we reach the leaf node, backtracking is required.
 - bactracking is achieved by stack (LIFO).

While we reach the leaf node everytime, we keep pushing nodes to stack.
 - the stack popping will help bactracking to the parent node each time.
*/