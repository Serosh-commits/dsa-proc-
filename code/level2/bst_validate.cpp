#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

bool isBST(Node* root, Node* minNode, Node* maxNode) {
    if(!root) return true;
    if((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data)) return false;
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

int main() {
    Node* root = new Node(10);
    cout << isBST(root, NULL, NULL) << endl;
    return 0;
}
