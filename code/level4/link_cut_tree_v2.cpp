#include<bits/stdc++.h>
using namespace std;

struct Node { int ch[2], p, rev; Node() { ch[0] = ch[1] = p = rev = 0; } };
const int MAXN = 100005; Node tr[MAXN];
bool isRoot(int x) { return tr[tr[x].p].ch[0] != x && tr[tr[x].p].ch[1] != x; }
void pushDown(int x) { if(tr[x].rev) { swap(tr[x].ch[0], tr[x].ch[1]); tr[tr[x].ch[0]].rev ^= 1; tr[tr[x].ch[1]].rev ^= 1; tr[x].rev = 0; } }
void rotate(int x) {
    int y = tr[x].p, z = tr[y].p, k = (tr[y].ch[1] == x);
    if(!isRoot(y)) tr[z].ch[tr[z].ch[1] == y] = x;
    tr[x].p = z; tr[y].ch[k] = tr[x].ch[k ^ 1]; tr[tr[x].ch[k ^ 1]].p = y; tr[x].ch[k ^ 1] = y; tr[y].p = x;
}
void splay(int x) {
    static int st[MAXN]; int top = 0, cur = x; st[++top] = cur;
    while(!isRoot(cur)) st[++top] = cur = tr[cur].p;
    while(top) pushDown(st[top--]);
    while(!isRoot(x)) { int y = tr[x].p, z = tr[y].p; if(!isRoot(y)) (tr[y].ch[1] == x) ^ (tr[z].ch[1] == y) ? rotate(x) : rotate(y); rotate(x); }
}
void access(int x) { for(int y = 0; x; y = x, x = tr[x].p) { splay(x); tr[x].ch[1] = y; } }
void makeRoot(int x) { access(x); splay(x); tr[x].rev ^= 1; }
void link(int x, int y) { makeRoot(x); tr[x].p = y; }
void cut(int x, int y) { makeRoot(x); access(y); splay(y); if(tr[y].ch[0] == x && tr[x].ch[1] == 0) { tr[y].ch[0] = tr[x].p = 0; } }

int main() {
    link(1, 2); cut(1, 2);
    return 0;
}
