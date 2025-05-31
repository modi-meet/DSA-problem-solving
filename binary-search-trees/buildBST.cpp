class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end){
    if(st > end) return nullptr;

    int mid = st + (end-st) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = helper(nums, st, mid-1);
    node->right = helper(nums, mid+1, end);

    return node;
  }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};

// TIME COMPLEXITY  : O(n)

/*
    we have to create a balanced-BST from the sorted array

    => nodes in left and nodes in right, their number difference cannot differ >1 
    => since the array is sorted, we can find middle node and point it as the root
        - from st to mid-1 will form the left subtree
        - and similarly, from mid+1 to end will form the right subtree
    => we can use recursion to build these subtrees each time  
*/