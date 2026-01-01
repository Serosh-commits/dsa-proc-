#include <bits/stdc++.h>
using namespace std;

struct LearnedBloom {
    vector<bool> filter;
    int size;
    LearnedBloom(int n) : size(n), filter(n, false) {}
    void insert(int x) { filter[x % size] = true; }
    bool query(int x) { return filter[x % size]; }
};

int main() {
    LearnedBloom lb(100);
    lb.insert(10);
    cout << lb.query(10) << " " << lb.query(20) << endl;
    return 0;
}
