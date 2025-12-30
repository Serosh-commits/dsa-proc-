#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

int height(Node* root, int& diameter) {
    if(!root) return 0;
    int lh = height(root->left, diameter), rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    int diameter = 0;
    height(root, diameter);
    cout << diameter << endl;
    return 0;
}
