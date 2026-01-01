#include <bits/stdc++.h>
using namespace std;

struct PostQuantumTree {
    struct Node {
        int val;
        Node *l, *r;
        Node(int v) : val(v), l(nullptr), r(nullptr) {}
    };
    Node* root;
    PostQuantumTree() : root(nullptr) {}
};

int main() {
    PostQuantumTree pqt;
    return 0;
}
