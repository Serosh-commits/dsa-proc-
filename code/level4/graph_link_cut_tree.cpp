#include <bits/stdc++.h>
using namespace std;

struct LCTNode {
    int ch[2], p;
    bool rev;
    int val, sum;

    LCTNode() {
        ch[0] = ch[1] = p = 0;
        rev = false;
        val = sum = 0;
    }
};

struct LinkCutTree {
    vector<LCTNode> nodes;

    LinkCutTree(int n) : nodes(n + 1) {}

    bool is_root(int x) {
        return nodes[nodes[x].p].ch[0] != x && nodes[nodes[x].p].ch[1] != x;
    }

    void push_up(int x) {
        nodes[x].sum = nodes[nodes[x].ch[0]].sum ^ nodes[nodes[x].ch[1]].sum ^ nodes[x].val;
    }

    void push_down(int x) {
        if (nodes[x].rev) {
            swap(nodes[x].ch[0], nodes[x].ch[1]);
            nodes[nodes[x].ch[0]].rev ^= 1;
            nodes[nodes[x].ch[1]].rev ^= 1;
            nodes[x].rev = 0;
        }
    }

    void rotate(int x) {
        int y = nodes[x].p, z = nodes[y].p;
        int k = (nodes[y].ch[1] == x);
        if (!is_root(y)) nodes[z].ch[nodes[z].ch[1] == y] = x;
        nodes[x].p = z;
        nodes[y].ch[k] = nodes[x].ch[k ^ 1];
        nodes[nodes[x].ch[k ^ 1]].p = y;
        nodes[x].ch[k ^ 1] = y;
        nodes[y].p = x;
        push_up(y); push_up(x);
    }

    void splay(int x) {
        static int stk[100005];
        int top = 0, cur = x;
        stk[++top] = cur;
        while (!is_root(cur)) stk[++top] = cur = nodes[cur].p;
        while (top) push_down(stk[top--]);
        while (!is_root(x)) {
            int y = nodes[x].p, z = nodes[y].p;
            if (!is_root(y))
                (nodes[y].ch[1] == x) ^ (nodes[z].ch[1] == y) ? rotate(x) : rotate(y);
            rotate(x);
        }
    }

    void access(int x) {
        for (int y = 0; x; y = x, x = nodes[x].p) {
            splay(x); nodes[x].ch[1] = y; push_up(x);
        }
    }

    void make_root(int x) {
        access(x); splay(x); nodes[x].rev ^= 1;
    }

    void link(int x, int y) {
        make_root(x); nodes[x].p = y;
    }

    void cut(int x, int y) {
        make_root(x); access(y); splay(y);
        if (nodes[y].ch[0] == x && !nodes[x].ch[1]) {
            nodes[y].ch[0] = nodes[x].p = 0;
            push_up(y);
        }
    }
};

int main() {
    LinkCutTree lct(10);
    lct.link(1, 2);
    lct.link(2, 3);
    cout << "LCT Link(1,2) and Link(2,3) completed." << endl;
    return 0;
}
