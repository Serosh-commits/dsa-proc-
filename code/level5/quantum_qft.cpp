#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

void qft(vector<complex<double>>& a) {
    int n = a.size();
    for (int j = 0; j < n; j++) {
        complex<double> sum(0, 0);
        for (int k = 0; k < n; k++) {
            double angle = 2 * PI * j * k / n;
            sum += a[k] * complex<double>(cos(angle), sin(angle));
        }
        a[j] = sum / sqrt(n);
    }
}

int main() {
    vector<complex<double>> a = {{1, 0}, {0, 0}, {0, 0}, {0, 0}};
    qft(a);
    for (auto x : a) cout << x << " ";
    cout << endl;
    return 0;
}
