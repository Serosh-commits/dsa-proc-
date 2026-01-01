#include <bits/stdc++.h>
using namespace std;

const int N_DIM = 64;
const int M_DIM = 128;
const int Q_MOD = 257;

struct LatticeHash {
    vector<vector<int>> A;

    LatticeHash() {
        A.resize(N_DIM, vector<int>(M_DIM));
        for (int i = 0; i < N_DIM; i++) {
            for (int j = 0; j < M_DIM; j++) {
                A[i][j] = rand() % Q_MOD;
            }
        }
    }

    vector<int> hash(const vector<int>& m) {
        vector<int> res(N_DIM, 0);
        for (int i = 0; i < N_DIM; i++) {
            for (int j = 0; j < M_DIM; j++) {
                res[i] = (res[i] + A[i][j] * m[j]) % Q_MOD;
            }
        }
        return res;
    }
};

int main() {
    LatticeHash lh;
    vector<int> message(M_DIM, 0);
    message[0] = 1; message[10] = 5;

    vector<int> h = lh.hash(message);
    cout << "Lattice Hash (first 5 components): ";
    for (int i = 0; i < 5; i++) cout << h[i] << " ";
    cout << endl;

    return 0;
}
