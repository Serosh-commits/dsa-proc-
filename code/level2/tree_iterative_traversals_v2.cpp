#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

void iterativeInorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty()) {
        while(curr) { s.push(curr); curr = curr->left; }
        curr = s.top(); s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2); root->right = new Node(3);
    iterativeInorder(root);
    return 0;
}
