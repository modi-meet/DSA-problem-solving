/*
To delete a node from BST,
  - we find the node
  - and then delete it

**After deleting the node, the BST properties should be satisfied!
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else { //found the root; perform deletion
            if(root->left == NULL && root->right == NULL){ //no child
                return NULL;
            }
            
            if (root->left == NULL || root->right == NULL) { //only one child
                return root->left != NULL ? root->left : root->right;
            }
            
            //both child
            TreeNode* temp = root->right;
            while(temp->left) temp = temp->left; //Successor (min of right subtree)

            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);  
        }

        return root;
    }
};

// TIME COMPLEXITY : O(height of the tree) ~ O(logN)
//                   O(N) worst case

//Explanation
/*
 while deleting a node,
 there are 3 total cases to look after: the node has
   1. no child
   2. only one child
   3. both child

    for 2 child case(3), there are two wanys to insert,
        i. connect root node to key.right, and join key.left to key.right -> lowest value (successor)

        or

        ii. connect root node to key.left and join key.right to key.left -> highest value (predecessor)
*/