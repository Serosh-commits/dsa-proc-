#include <bits/stdc++.h>
using namespace std;

struct PostQuantumDS {
    vector<int> lattice_point;
    PostQuantumDS(int n) : lattice_point(n, 0) {}
    void perturb() {
        for (int& x : lattice_point) x += rand() % 10 - 5;
    }
};

int main() {
    PostQuantumDS ds(5);
    ds.perturb();
    return 0;
}
