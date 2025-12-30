#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left); cout << root->data << " "; inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    inorder(root);
    return 0;
}
