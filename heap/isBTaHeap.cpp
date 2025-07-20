class Solution {
private
    bool isCBT(Node* root, int size, int i){
        if(root == NULL) return true;
        
        if(i >= size) return false; // invalid; current node count exceeds total node count

        bool left = isCBT(root->left, size, 2*i+1);
        bool right = isCBT(root->right, size, 2*i+2);
        return left && right;
    }
    
    bool isMaxHeap(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true; // leaf node
        
        else if(root->right == NULL){ // only left node exists
            return root->data > root->left->data;
        } 
        // both nodes exist
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        
        return (root->data > root->left->data && root->data > root->right->data) && left && right;
    }
    
    int countNodes(Node* root){
        if(root == NULL) return 0;
        
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
public:
    bool isHeap(Node* tree) {
        int n = countNodes(tree); // total nodes in the tree
        
        if(isCBT(tree, n, 0) && isMaxHeap(tree)) return true;
        return false;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) = O(N) worst case, H - height of the tree

/*
2 main conditions:

1. Tree should be Complete Binary Tree
2. It should be following Max-heap property

For CBT:
- total 3 type of nodes :
- leaf node (node is valid if curr_count matches total_count)
- only left child exist (last level of tree; count should match)
- Both child exist (recursively call for left & right child)

For Max_heap:
- leaf node (node is valid)
- only left child exist (last level of tree; value must be lesser than parent)
- Both child exist (recursively call for left & right child; both follows max_heap property then valid)
*/
