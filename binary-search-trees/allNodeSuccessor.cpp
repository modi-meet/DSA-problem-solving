// Populate Inorder Successor for all nodes
// The next pointer for every node should point to the Inorder successor of the node.

/*
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/

// using RECURSION
class Solution {
  public:  
    Node* prev = NULL;

    void helper(Node* root){
        if(root == NULL) return; 
       
       //Left
        helper(root->left);
        
       //Node
        if(prev != NULL) {
            prev->next = root;
        }
        prev = root;
        
       //Right
        helper(root->right);
    }

    void populateNext(Node *root) {
        helper(root);
    }
};
// TIME COMPLEXITY : O(n)
// space complexity : O(H), recursion stack

// using Right → Node → Left (Recursion)
class Solution {
  public:
    Node* nextRight = NULL;
    
    void helper(Node* root){
        if(root == NULL) return;
       
       //Right
        helper(root->right);
       //Node
        root->next = nextRight;
        nextRight = root;
       //Left
        helper(root->left);
    }

    void populateNext(Node *root) {
        helper(root);
    }
};

// TIME COMPLEXITY : O(n)
// space complexity : O(H), recursion stack

// Interative Approach (using Morris Traversal)
class Solution {
  public:
    void populateNext(Node *root) {
        stack<Node*> st;
        Node* node = root;
        Node* prev = NULL;
        
        while(node || !st.empty()){
            //Left
            while(node){
                st.push(node);
                node = node->left;
            }
            
            node = st.top();
            st.pop();
            
            if(prev != NULL) prev->next = node;
            
            prev = node;
            
            //Right
            node = node->right;
        }
    }
};
// TIME COMPLEXITY : O(n)
// space complexity : O(H), stack datastructure

/*
Explanation

Understand the problem-
    - In BST, every parent node has two node, left and right
    - But here, Every node has one more pointer named 'next'
    - if node has no inorder successor point 'next' pointer to NULL

Task-
To point/connect the next pointer of current node to its inorder successor, for all the nodes of the BST

Steps & Aproaches-

1. Recursive approach (Inorder)

By definition, successor of a node is - the left most node in the right subtree.
    - So, inorder traversal does the exact same thing
    - After reaching to left most node of the tree, 
        it bactracks to node and goes to the left most node of right subtree, if any.

Steps : 
  - Traverse the BST inorder recursively,
  - maintain a node called 'prev', related to previous node
  - for every node, connect the current node's next pointer to prev and update prev to curr node everytime.

2. Iterative Approach (Morris Traversal)

It is exactly same as Morris Inorder traversal, 
    - Additionally, include 'prev' pointer for connecting 'next'.
    - Morris Inorder traversal include using stack for backtraking.
*/