#include<bits/stdc++.h>
using namespace std;

struct LatticeHash {
    vector<vector<int>> matrix;
    int n, m, q;
    LatticeHash(int _n, int _m, int _q) : n(_n), m(_m), q(_q) {
        matrix.resize(n, vector<int>(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) matrix[i][j] = rand() % q;
    }
    vector<int> hash(vector<int>& input) {
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i] = (res[i] + matrix[i][j] * input[j]) % q;
            }
        }
        return res;
    }
};

int main() {
    LatticeHash lh(4, 8, 101);
    vector<int> input = {1, 0, 1, 1, 0, 0, 1, 0};
    vector<int> h = lh.hash(input);
    for(int x : h) cout << x << " ";
    return 0;
}
