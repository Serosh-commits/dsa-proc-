#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* lca(Node* root, int n1, int n2) {
    if(!root) return NULL;
    if(root->data > n1 && root->data > n2) return lca(root->left, n1, n2);
    if(root->data < n1 && root->data < n2) return lca(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8); root->right = new Node(22);
    Node* res = lca(root, 8, 22);
    cout << res->data << endl;
    return 0;
}
