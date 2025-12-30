#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data; Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int rangeSumBST(Node* root, int low, int high) {
    if(!root) return 0;
    if(root->data < low) return rangeSumBST(root->right, low, high);
    if(root->data > high) return rangeSumBST(root->left, low, high);
    return root->data + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

int main() {
    Node* root = new Node(10);
    cout << rangeSumBST(root, 5, 15) << endl;
    return 0;
}
