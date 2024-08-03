#include <iostream>
using namespace std;

// Create a Node for the binary tree

struct Node{
    int value;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int k) : value(k), left(nullptr), right(nullptr){}
};

Node *insert(Node* root, int value){
    // if the tree is empty, return a new node 
    if(root == nullptr){
        return new Node(value);
    }

    // otherwise , recur down the tree
    if(value<root->value){
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to do an in-order traversal of the binary tree
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}