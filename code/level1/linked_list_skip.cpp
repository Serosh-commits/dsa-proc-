#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    vector<Node*> forward;
    Node(int k, int level) : key(k), forward(level + 1, NULL) {}
};

int main() {
    Node* head = new Node(-1, 3);
    return 0;
}
