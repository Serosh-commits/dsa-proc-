#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *l, *r, *p;
    Node(int v) : val(v), l(nullptr), r(nullptr), p(nullptr) {}
};

struct TopTree {
    Node* root;
    TopTree() : root(nullptr) {}
    void compress(Node* u) {
        if (!u) return;
        cout << "Compressing node " << u->val << endl;
    }
};

int main() {
    TopTree tt;
    tt.compress(new Node(1));
    return 0;
}
