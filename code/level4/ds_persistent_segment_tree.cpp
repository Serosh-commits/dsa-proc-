#include<bits/stdc++.h>
using namespace std;

struct Node { int val, l, r; };
vector<Node> tree(1);

int update(int prev, int start, int end, int idx, int val) {
    int node = tree.size(); tree.emplace_back(); tree[node] = tree[prev];
    if(start == end) { tree[node].val = val; return node; }
    int mid = (start + end) / 2;
    if(idx <= mid) tree[node].l = update(tree[prev].l, start, mid, idx, val);
    else tree[node].r = update(tree[prev].r, mid + 1, end, idx, val);
    tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
    return node;
}

int main() {
    int root0 = 0; int root1 = update(root0, 0, 9, 5, 10);
    return 0;
}
