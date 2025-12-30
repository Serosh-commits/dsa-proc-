#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val, priority, size; Node *l, *r;
    Node(int v) : val(v), priority(rand()), size(1), l(NULL), r(NULL) {}
};

int sz(Node* t) { return t ? t->size : 0; }
void update(Node* t) { if(t) t->size = 1 + sz(t->l) + sz(t->r); }

void split(Node* t, int k, Node*& l, Node*& r) {
    if(!t) { l = r = NULL; return; }
    int cur_k = sz(t->l);
    if(cur_k < k) { split(t->r, k - cur_k - 1, t->r, r); l = t; }
    else { split(t->l, k, l, t->l); r = t; }
    update(t);
}

void merge(Node*& t, Node* l, Node* r) {
    if(!l || !r) t = l ? l : r;
    else if(l->priority > r->priority) { merge(l->r, l->r, r); t = l; }
    else { merge(r->l, l, r->l); t = r; }
    update(t);
}

int main() {
    Node* root = NULL; merge(root, root, new Node(10));
    return 0;
}
