#include<bits/stdc++.h>
using namespace std;

void build(int node, int start, int end, vector<int>& tree, vector<int>& arr) {
    if(start == end) { tree[node] = arr[start]; return; }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, tree, arr); build(2 * node + 1, mid + 1, end, tree, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int start, int end, int idx, int val, vector<int>& tree) {
    if(start == end) { tree[node] = val; return; }
    int mid = (start + end) / 2;
    if(idx <= mid) update(2 * node, start, mid, idx, val, tree);
    else update(2 * node + 1, mid + 1, end, idx, val, tree);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r, vector<int>& tree) {
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r, tree) + query(2 * node + 1, mid + 1, end, l, r, tree);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; int n = arr.size();
    vector<int> tree(4 * n); build(1, 0, n - 1, tree, arr);
    return 0;
}
