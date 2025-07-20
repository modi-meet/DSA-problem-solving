// BST to min heap
// Given the root node of a Binary Search Tree. 
// Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node.
// This condition is applied on all the nodes in the converted Max Heap.

class Solution {
    void getDecOrder(vector<int> &po, Node* root){
        if(root == NULL) return;
        // Root-Node-Left
        getDecOrder(po, root->right);
        po.push_back(root->data);
        getDecOrder(po, root->left);
    }
    
    // Change values of the nodes according to max Heap property.
    void fillMaxHeap(Node* root, vector<int> &DecOrder, int &i){
        if(root == NULL) return;
        
        root->data = DecOrder[i++];
        fillMaxHeap(root->right, DecOrder, i);
        fillMaxHeap(root->left, DecOrder, i);
    }
    
public:
    void convertToMaxHeapUtil(Node* root) {
        if(root == NULL) return;
        
        vector<int> DecOrder; // postorder traversal value array
        getDecOrder(DecOrder, root);
        
        int idx = 0;
        fillMaxHeap(root, DecOrder, idx);
        return;
    }
};
// Time Complexity: O(N),
// Space Complexity: O(N) (for postorder array) + O(N) (in worst case) (for recursion stack)
