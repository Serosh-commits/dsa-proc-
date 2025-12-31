#include<bits/stdc++.h>
using namespace std;

struct Node { int next[26], fail, end; Node() { memset(next, 0, sizeof next); fail = end = 0; } };
vector<Node> trie(1);

void insert(string s) {
    int u = 0;
    for(char c : s) { if(!trie[u].next[c - 'a']) { trie[u].next[c - 'a'] = trie.size(); trie.emplace_back(); } u = trie[u].next[c - 'a']; }
    trie[u].end++;
}

void build() {
    queue<int> q; for(int i = 0; i < 26; i++) if(trie[0].next[i]) q.push(trie[0].next[i]);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++) {
            if(trie[u].next[i]) { trie[trie[u].next[i]].fail = trie[trie[u].fail].next[i]; q.push(trie[u].next[i]); }
            else trie[u].next[i] = trie[trie[u].fail].next[i];
        }
    }
}

int main() {
    insert("he"); insert("she"); insert("hers"); insert("his");
    build();
    return 0;
}
