#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void morrisInorder(Node* root) {
    Node *curr = root, *pre;
    while(curr) {
        if(!curr->left) { cout << curr->data << " "; curr = curr->right; }
        else {
            pre = curr->left;
            while(pre->right && pre->right != curr) pre = pre->right;
            if(!pre->right) { pre->right = curr; curr = curr->left; }
            else { pre->right = NULL; cout << curr->data << " "; curr = curr->right; }
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    morrisInorder(root);
    return 0;
}
