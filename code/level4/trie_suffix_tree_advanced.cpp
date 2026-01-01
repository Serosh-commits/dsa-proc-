#include <bits/stdc++.h>
using namespace std;

struct STNode {
    int start, *end;
    int suffix_link;
    map<char, int> next;

    STNode(int s, int* e) : start(s), end(e), suffix_link(0) {}
};

struct SuffixTree {
    string text;
    vector<STNode*> nodes;
    int root, last_added, active_node, active_edge, active_len, remainder, leaf_end;

    SuffixTree(string s) : text(s) {
        leaf_end = -1;
        root = active_node = newNode(-1, new int(-1));
        active_edge = -1;
        active_len = 0;
        remainder = 0;
        for (int i = 0; i < text.length(); i++) extend(i);
    }

    int newNode(int start, int* end) {
        nodes.push_back(new STNode(start, end));
        return nodes.size() - 1;
    }

    int edgeLength(int n) {
        return *(nodes[n]->end) - nodes[n]->start + 1;
    }

    bool walkDown(int n) {
        if (active_len >= edgeLength(n)) {
            active_edge += edgeLength(n);
            active_len -= edgeLength(n);
            active_node = n;
            return true;
        }
        return false;
    }

    void extend(int pos) {
        leaf_end = pos;
        remainder++;
        last_added = 0;
        while (remainder > 0) {
            if (active_len == 0) active_edge = pos;
            if (nodes[active_node]->next.find(text[active_edge]) == nodes[active_node]->next.end()) {
                nodes[active_node]->next[text[active_edge]] = newNode(pos, &leaf_end);
                if (last_added != 0) nodes[last_added]->suffix_link = active_node;
                last_added = active_node;
            } else {
                int next = nodes[active_node]->next[text[active_edge]];
                if (walkDown(next)) continue;
                if (text[nodes[next]->start + active_len] == text[pos]) {
                    active_len++;
                    if (last_added != 0) nodes[last_added]->suffix_link = active_node;
                    last_added = active_node;
                    break;
                }
                int* split_end = new int(nodes[next]->start + active_len - 1);
                int split = newNode(nodes[next]->start, split_end);
                nodes[active_node]->next[text[active_edge]] = split;
                nodes[split]->next[text[pos]] = newNode(pos, &leaf_end);
                nodes[next]->start += active_len;
                nodes[split]->next[text[nodes[next]->start]] = next;
                if (last_added != 0) nodes[last_added]->suffix_link = split;
                last_added = split;
            }
            remainder--;
            if (active_node == root && active_len > 0) {
                active_len--;
                active_edge = pos - remainder + 1;
            } else if (active_node != root) {
                active_node = nodes[active_node]->suffix_link;
            }
        }
    }
};

int main() {
    SuffixTree st("abcabxabcd$");
    cout << "Suffix Tree construction completed." << endl;
    return 0;
}
