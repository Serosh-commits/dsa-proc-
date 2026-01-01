#include <bits/stdc++.h>
using namespace std;

struct SAMNode {
    int len, link;
    map<char, int> next;
    int first_pos;
    bool is_clone;

    SAMNode() : len(0), link(-1), first_pos(-1), is_clone(false) {}
};

struct SuffixAutomaton {
    vector<SAMNode> st;
    int last;

    SuffixAutomaton(string s) {
        st.push_back(SAMNode());
        last = 0;
        for (char c : s) extend(c);
    }

    void extend(char c) {
        int cur = st.size();
        st.push_back(SAMNode());
        st[cur].len = st[last].len + 1;
        st[cur].first_pos = st[cur].len - 1;
        int p = last;
        while (p != -1 && st[p].next.find(c) == st[p].next.end()) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = st.size();
                st.push_back(SAMNode());
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                st[clone].first_pos = st[q].first_pos;
                st[clone].is_clone = true;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    bool contains(string t) {
        int cur = 0;
        for (char c : t) {
            if (st[cur].next.find(c) == st[cur].next.end()) return false;
            cur = st[cur].next[c];
        }
        return true;
    }
};

int main() {
    SuffixAutomaton sam("abbab");
    cout << "Contains 'aba': " << (sam.contains("aba") ? "Yes" : "No") << endl;
    cout << "Contains 'abb': " << (sam.contains("abb") ? "Yes" : "No") << endl;
    return 0;
}
