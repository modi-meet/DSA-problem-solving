#include<iostream>
#include<vector>
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

Node* insert(Node* node, int val){  //root and arr[i] value as parameters
    if(node == NULL) return new Node(val);

    if(node->data > val) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }

    return node;
}

//build the binary search tree
Node* buildBST(vector<int> &arr){ 
    Node* root = NULL;

    for(int val : arr){
        root = insert(root, val);
    }

    return root;
}

//inorder traversal for printing
void inOrder(Node* root){ 
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->data << endl;

    inOrder(root->right);
}

int main(){
    vector<int> arr = {3, 2, 1, 5, 6, 4}; //unique

    Node* root = buildBST(arr);
    inOrder(root);
    cout << endl;

    return 0;
}

/*
username: meet modi
date: 30th May, 2025 
*/