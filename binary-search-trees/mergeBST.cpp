// Merge two BST's
// return a vector that contains the merged values
class Solution {
  public:
    void BSTstack(Node* root, stack<int> &st){
        if(root == NULL) return;

        //reverse inorder because of stack data structure, LIFO
        BSTstack(root->right, st);
        st.push(root->data);
        BSTstack(root->left, st);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        stack<int> st1, st2;
        vector<int> ans;
        
        BSTstack(root1, st1);
        BSTstack(root2, st2);
        
        while(!st1.empty() && !st2.empty()){
            if(st1.top() <= st2.top()) {
                ans.push_back(st1.top()); 
                st1.pop();
            } else {
                ans.push_back(st2.top()); 
                st2.pop();
            }
        }
        
        while(!st1.empty()){
                ans.push_back(st1.top());
                st1.pop();
        }
        while(!st2.empty()){
                ans.push_back(st2.top());
                st2.pop();
        }
        return ans;
    }
};

// TIME COMPLEXITY : O(n1 + n2) (all nodes of BST) (n1 & n2 - nodes of root1 & root2)
// Space Complexity : O(n1 + n2) (Two stacks) 

/*
Explanation

To merge given two BSTs,
    - traverse both the BSTs inorder and store them in a list
    - use vector or stack for storing. 
        - if stack is used traversal will right->node->left because LIFO property of Stack
    -Apply merge sort on both the lists/stacks, and return ans 
*/