#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node *left, *right;
    Node(int val, Node* l = NULL, Node* r = NULL) : data(val), left(l), right(r) {}
};

Node* insert(Node* root, int val) {
    if(!root) return new Node(val);
    if(val < root->data) return new Node(root->data, insert(root->left, val), root->right);
    return new Node(root->data, root->left, insert(root->right, val));
}

int main() {
    Node* v1 = insert(NULL, 10);
    Node* v2 = insert(v1, 5);
    return 0;
}
