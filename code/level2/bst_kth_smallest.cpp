#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void kthSmallest(Node* root, int& k, int& res) {
    if(!root) return;
    kthSmallest(root->left, k, res);
    if(--k == 0) { res = root->data; return; }
    kthSmallest(root->right, k, res);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10); root->right = new Node(30);
    int k = 2, res = -1;
    kthSmallest(root, k, res);
    cout << res << endl;
    return 0;
}
