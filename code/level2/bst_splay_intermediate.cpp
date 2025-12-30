#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key; Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

Node* rightRotate(Node* x) {
    Node* y = x->left; x->left = y->right; y->right = x; return y;
}

Node* leftRotate(Node* x) {
    Node* y = x->right; x->right = y->left; y->left = x; return y;
}

Node* splay(Node* root, int key) {
    if(!root || root->key == key) return root;
    if(root->key > key) {
        if(!root->left) return root;
        if(root->left->key > key) { root->left->left = splay(root->left->left, key); root = rightRotate(root); }
        else if(root->left->key < key) { root->left->right = splay(root->left->right, key); if(root->left->right) root->left = leftRotate(root->left); }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if(!root->right) return root;
        if(root->right->key > key) { root->right->left = splay(root->right->left, key); if(root->right->left) root->right = rightRotate(root->right); }
        else if(root->right->key < key) { root->right->right = splay(root->right->right, key); root = leftRotate(root); }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

int main() {
    Node* root = new Node(100);
    root = splay(root, 50);
    return 0;
}
