#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data, size; Node *left, *right;
    Node(int val) : data(val), size(1), left(NULL), right(NULL) {}
};

int getSize(Node* n) { return n ? n->size : 0; }

Node* insert(Node* root, int data) {
    if(!root) return new Node(data);
    if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    root->size = 1 + getSize(root->left) + getSize(root->right);
    return root;
}

int kthSmallest(Node* root, int k) {
    int leftSize = getSize(root->left);
    if(k == leftSize + 1) return root->data;
    if(k <= leftSize) return kthSmallest(root->left, k);
    return kthSmallest(root->right, k - leftSize - 1);
}

int main() {
    Node* root = NULL; root = insert(root, 20);
    cout << kthSmallest(root, 1) << endl;
    return 0;
}
