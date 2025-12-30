#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int x) {
    if(!root) return new Node(x);
    if(x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* search(Node* root, int x) {
    if(!root || root->data == x) return root;
    if(x < root->data) return search(root->left, x);
    return search(root->right, x);
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    cout << (search(root, 3) ? "found" : "not found") << endl;
    return 0;
}
