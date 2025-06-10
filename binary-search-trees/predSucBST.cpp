// find the in-order Successor and Predecessor of the given key.
// If key doesn't exist than return closest smaller (predecessor) and closest greater (successor) nodes 

class Solution {
public:
    Node* pred = NULL;
    Node* succ = NULL;
      
    Node* findKeyNode(Node* root, int key){
        if(root == NULL || root->data == key) return root;
        
        if(key < root->data) {
            succ = root;
            return findKeyNode(root->left, key);
        }
        else {
            pred = root;
            return findKeyNode(root->right, key);
        }
    }
    
    void findPredecessor(Node* node){
        Node* temp = NULL;
        
        while(node) {
            temp = node;
            node = node->right;
        }
        
        pred = temp;
    }
    
    void findSuccessor(Node* node){
        Node* temp = NULL;
        
        while(node) {
            temp = node;
            node = node->left;
        }
        
        succ = temp;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {        
        Node* node = findKeyNode(root, key);
        
        if (node) {
            if (node->left)  findPredecessor(node->left);
            if (node->right) findSuccessor(node->right);
        }

        return {pred, succ};
    }
};
// TIME COMPLEXITY: TC - O(H) H - height of BST

/*
Explanation

 successor - the closest next greater node 
 predecessor - the closest previous lesser node

Steps - 
    1. Traverse to find the key node
    2. if key node found,
        - go to left subtree, find predecessor
        - go to right subtree, find successor
    3. if key NOT found, return 
        - closest smaller (predecessor) node
        - & closest greater (successor) node to key node
    4. Base case,
        - If either predecessor or successor is not found, then set it to NULL.
*/