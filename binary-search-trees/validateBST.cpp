// Validate whether the given Binary is BST or not.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
private:
    bool helper(TreeNode* root, int min, int max){
        if(root == NULL) return true;

        if(root->val >= max || root->val <= min) return false;

        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
};

//TIME COMPLEXITY : O(n) for traversal

/*
---Explanation---

BST are type of Binary Treess, where:
-left child's value is lower and
-right child's value is higher,
    than the parent node throughout the tree.
    
For left child node - check if it is less than its parent node
For right child node - check if it is greater than parent node 

While recursion, for left subtree call, 
    -we pass root->val as max, max value that the subtree can have
For right subtree call, 
    -we pass root->val as min, mix value that the subtree should have  

if root.val is less than min or greater than max than return false

// Base case will be, if root == Null; we reached the leaf node, return true as no error were found in between.

And, that's it! 
*/