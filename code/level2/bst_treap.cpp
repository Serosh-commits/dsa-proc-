#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key, priority; Node *left, *right;
    Node(int k) : key(k), priority(rand()), left(NULL), right(NULL) {}
};

Node* rotateRight(Node* y) {
    Node* x = y->left; Node* T2 = x->right;
    x->right = y; y->left = T2; return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right; Node* T2 = y->left;
    y->left = x; x->right = T2; return y;
}

Node* insert(Node* root, int key) {
    if(!root) return new Node(key);
    if(key <= root->key) {
        root->left = insert(root->left, key);
        if(root->left->priority > root->priority) root = rotateRight(root);
    } else {
        root->right = insert(root->right, key);
        if(root->right->priority > root->priority) root = rotateLeft(root);
    }
    return root;
}

int main() {
    Node* root = NULL; root = insert(root, 50);
    return 0;
}
