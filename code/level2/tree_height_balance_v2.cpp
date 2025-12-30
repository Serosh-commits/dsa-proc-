#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root) {
    if(!root) return true;
    int lh = height(root->left), rh = height(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    Node* root = new Node(1);
    cout << isBalanced(root) << endl;
    return 0;
}
