#include<bits/stdc++.h>
using namespace std;

struct Node { int len, link, next[26]; };
vector<Node> st(1); int last = 0;

void extend(char c) {
    int cur = st.size(); st.emplace_back(); st[cur].len = st[last].len + 1;
    int p = last; while(p != -1 && !st[p].next[c - 'a']) { st[p].next[c - 'a'] = cur; p = st[p].link; }
    if(p == -1) st[cur].link = 0;
    else {
        int q = st[p].next[c - 'a'];
        if(st[p].len + 1 == st[q].len) st[cur].link = q;
        else {
            int clone = st.size(); st.emplace_back(); st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof st[q].next); st[clone].link = st[q].link;
            while(p != -1 && st[p].next[c - 'a'] == q) { st[p].next[c - 'a'] = clone; p = st[p].link; }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int main() {
    st[0].len = 0; st[0].link = -1;
    extend('a'); extend('b');
    return 0;
}
