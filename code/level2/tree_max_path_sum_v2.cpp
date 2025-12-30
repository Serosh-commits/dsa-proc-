#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

int maxPathSumUtil(Node* root, int& res) {
    if(!root) return 0;
    int l = maxPathSumUtil(root->left, res), r = maxPathSumUtil(root->right, res);
    int max_single = max(max(l, r) + root->data, root->data);
    int max_top = max(max_single, l + r + root->data);
    res = max(res, max_top);
    return max_single;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(2); root->right = new Node(10);
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    cout << res << endl;
    return 0;
}
