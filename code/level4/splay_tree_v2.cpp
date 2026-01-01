#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *l, *r, *p;
    Node(int k) : key(k), l(0), r(0), p(0) {}
};

void rotate(Node* x) {
    Node* y = x->p;
    Node* z = y->p;
    if(z) {
        if(z->l == y) z->l = x;
        else z->r = x;
    }
    x->p = z;
    if(y->l == x) {
        y->l = x->r;
        if(x->r) x->r->p = y;
        x->r = y;
    } else {
        y->r = x->l;
        if(x->l) x->l->p = y;
        x->l = y;
    }
    y->p = x;
}

void splay(Node*& root, Node* x) {
    while(x->p) {
        Node* y = x->p;
        Node* z = y->p;
        if(z) {
            if((z->l == y) == (y->l == x)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    root = x;
}

void insert(Node*& root, int k) {
    if(!root) { root = new Node(k); return; }
    Node* curr = root;
    Node* prev = 0;
    while(curr) {
        prev = curr;
        if(k < curr->key) curr = curr->l;
        else curr = curr->r;
    }
    Node* n = new Node(k);
    n->p = prev;
    if(k < prev->key) prev->l = n;
    else prev->r = n;
    splay(root, n);
}

int main() {
    Node* root = 0;
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    if(root) cout << root->key << endl;
    return 0;
}
