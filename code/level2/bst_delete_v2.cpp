#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node* minValueNode(Node* node) {
    Node* curr = node;
    while(curr && curr->left) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int key) {
    if(!root) return root;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(!root->left) { Node* temp = root->right; delete root; return temp; }
        else if(!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = new Node(50);
    root = deleteNode(root, 50);
    return 0;
}
