#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if(!root) return new Node(key);
    if(key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

bool search(Node* root, int key) {
    if(!root) return false;
    if(root->data == key) return true;
    if(root->data < key) return search(root->right, key);
    return search(root->left, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    cout << search(root, 50) << endl;
    return 0;
}
