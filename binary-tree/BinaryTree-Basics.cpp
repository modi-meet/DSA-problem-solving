#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public :
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        right = left = NULL;
    }
};

int idx = -1;
Node* buildTree(vector<int> &preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); //LEFT subtree
    root->right = buildTree(preorder); //RIGHT subtree

    return root;
}

//Preorder traversal : root -> left child -> right child
void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->data <<endl;
    preOrder(root->left);
    preOrder(root->right);
}
// Time Complexity: O(N)
// Space Complexity: O(H) (recursion call stack)

//Inorder traversal : left child -> root -> right child
void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << endl;

    inOrder(root->right);
}
// Time Complexity: O(N)
// Space Complexity: O(H) (recursion call stack)

//Postorder traversal : left child -> right child  -> root
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}
// Time Complexity: O(N)
// Space Complexity: O(H) (recursion call stack)

//Levelorder traversal : Breadth-First Search
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            } else 
                break;
        }

        cout << curr->data <<" ";

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}
// Time Complexity: O(N)
// Space Complexity: O(N) (queue)

int main(){ 
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout << endl; 

    cout<<"Preorder"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Postorder"<<endl;
    postOrder(root);
    cout<<"Levelorder"<<endl;
    levelOrder(root);
    
    return 0;
}