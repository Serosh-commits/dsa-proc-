#include <bits/stdc++.h>
using namespace std;

struct CompressedTrie {
    struct Node {
        map<string, Node*> children;
        bool isEnd;
        Node() : isEnd(false) {}
    };
    Node* root;
    CompressedTrie() : root(new Node()) {}
    void insert(string s) {
        Node* curr = root;
        curr->children[s] = new Node();
    }
};

int main() {
    CompressedTrie ct;
    ct.insert("hello");
    return 0;
}
