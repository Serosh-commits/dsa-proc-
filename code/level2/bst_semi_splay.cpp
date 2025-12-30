#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *l, *r, *p;
    Node(int k) : key(k), l(nullptr), r(nullptr), p(nullptr) {}
};

struct SemiSplayTree {
    Node* root;

    SemiSplayTree() : root(nullptr) {}

    void rotate(Node* x) {
        Node* y = x->p;
        if (!y) return;
        Node* z = y->p;
        if (z) {
            if (z->l == y) z->l = x;
            else z->r = x;
        }
        x->p = z;
        if (y->l == x) {
            y->l = x->r;
            if (x->r) x->r->p = y;
            x->r = y;
        } else {
            y->r = x->l;
            if (x->l) x->l->p = y;
            x->l = y;
        }
        y->p = x;
        if (!x->p) root = x;
    }

    void semi_splay(Node* x) {
        while (x->p) {
            rotate(x);
        }
    }

    void insert(int k) {
        if (!root) {
            root = new Node(k);
            return;
        }
        Node* curr = root;
        Node* p = nullptr;
        while (curr) {
            p = curr;
            if (k < curr->key) curr = curr->l;
            else curr = curr->r;
        }
        Node* newNode = new Node(k);
        newNode->p = p;
        if (k < p->key) p->l = newNode;
        else p->r = newNode;
        semi_splay(newNode);
    }
};

int main() {
    SemiSplayTree sst;
    sst.insert(10);
    sst.insert(20);
    sst.insert(5);
    cout << "Semi-Splay Tree Root: " << sst.root->key << endl;
    return 0;
}
