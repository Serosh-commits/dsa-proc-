#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 8;
    vector<double> prob(n, 0.0);
    prob[0] = 1.0;
    for (int step = 0; step < 5; step++) {
        vector<double> next(n, 0.0);
        for (int i = 0; i < n; i++) {
            next[(i + 1) % n] += prob[i] * 0.5;
            next[(i - 1 + n) % n] += prob[i] * 0.5;
        }
        prob = next;
    }
    for (int i = 0; i < n; i++) cout << i << ": " << prob[i] << endl;
    return 0;
}
