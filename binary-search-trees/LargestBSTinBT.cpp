// Given a binary tree, task is to 
// Return the size of the largest sub-tree which is also a BST
class Solution {
public:
    // Brute approach - TLE
    bool isBST(Node* root, int max, int min){
      if(root == NULL) return true;
      
      if(root->data < min || root->data > max) return false;
      
      return isBST(root->left, root->data, min) && isBST(root->right, max, root->data);
    }
    
    int nodeCount(Node* root){
        if(root == NULL) return 0;
        
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
    
    int max_node = 0;
    void dfs(Node* root){
        if(root == NULL) return;
        //L
        dfs(root->left);
        
        if(isBST(root, INT_MAX, INT_MIN)) 
            max_node = max(max_node, nodeCount(root));
        //R
        dfs(root->right);
    }

    int largestBst(Node *root) {
        dfs(root);
        
        return max_node;
    }
};
// TIME COMPLEXITY : O(n^2)
// Space Complexity : O(H) (height of the tree) (recursion stack)

class Info {
public:
        int nodeCnt;
        int max;
        int min;
        bool isBST;
};
class Solution {
public:
    Info solve(Node* root, int &max_node){
        if(root == NULL) {
            return {0, INT_MIN, INT_MAX, true}; 
        } //return 0;
        
        Info left  = solve(root->left, max_node);
        Info right = solve(root->right, max_node);
        
        Info currNode;
        currNode.nodeCnt = (left.nodeCnt + right.nodeCnt) + 1;
        currNode.max = max(root->data, right.max);
        currNode.min = min(root->data, left.min);
        
        if(left.isBST && right.isBST && (left.max < root->data && right.min > root->data)) 
            currNode.isBST = true;
        else
            currNode.isBST = false;
            
        if(currNode.isBST) max_node = max(max_node, currNode.nodeCnt);
        
        return currNode;
    }

    int largestBst(Node *root) {
        int max_node = 0;
        
        Info temp = solve(root, max_node);
        
        return max_node;
    }
};
// TIME COMPLEXITY : O(n) (all nodes of BT)
// Space Complexity : O(H) (height of the tree) (recursion stack)

/**********Explanation**********

BRUTE APPROACH -
    1. traverse every node 
    2. check whether it is BST or NOT
    3. count no. of nodes while checking

**Optimal Approach** -
    - Use extra class for - nodeCount, maxValue, minValue and isBST while traversing
    - this helps finding whether left and right subtree are BST or NOT in O(1). 
Steps: (Solve for one, rest will be taken care by Recursion)
    1. current node size = (leftBST size + rightBST size)+ 1
    2. current node's max will be right subtree's max or node's value
        - similarly left subtree's min value for node's min
    3. if right and left both subtrees are BST 
    And, 
        - right subtree's min should be greater than node's value
        - left subtree's max should be lesser than nodes's val
    then mark current node to be BST
    4. if current Node is BST, update ans
*/