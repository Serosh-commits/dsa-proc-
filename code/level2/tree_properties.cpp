#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node* root, int& res) {
    if(!root) return 0;
    int lh = diameter(root->left, res);
    int rh = diameter(root->right, res);
    res = max(res, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << height(root) << endl;
    int d = 0;
    diameter(root, d);
    cout << d << endl;
    return 0;
}
