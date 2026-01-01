#include <bits/stdc++.h>
using namespace std;

string pq_hash(string s) {
    unsigned long h = 5381;
    for (char c : s) h = ((h << 5) + h) + c;
    return to_string(h);
}

struct PQTrieNode {
    map<char, PQTrieNode*> children;
    string node_hash;
    bool is_end;

    PQTrieNode() : is_end(false), node_hash("") {}

    void update_hash() {
        string content = is_end ? "1" : "0";
        for (auto const& [c, child] : children) {
            content += c + child->node_hash;
        }
        node_hash = pq_hash(content);
    }
};

struct PQTrie {
    PQTrieNode* root;

    PQTrie() { root = new PQTrieNode(); }

    void insert(string word) {
        PQTrieNode* curr = root;
        vector<PQTrieNode*> path = {root};
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new PQTrieNode();
            }
            curr = curr->children[c];
            path.push_back(curr);
        }
        curr->is_end = true;
        for (int i = path.size() - 1; i >= 0; i--) {
            path[i]->update_hash();
        }
    }

    bool verify(string word) {
        PQTrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->is_end;
    }
};

int main() {
    PQTrie trie;
    trie.insert("quantum");
    trie.insert("resistant");
    cout << "Root Hash: " << trie.root->node_hash << endl;
    cout << "Verify 'quantum': " << (trie.verify("quantum") ? "Verified" : "Failed") << endl;
    return 0;
}
