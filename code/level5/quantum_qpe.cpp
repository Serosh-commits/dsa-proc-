#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

void qft_inv(vector<complex<double>>& a) {
    int n = a.size();
    for (int j = 0; j < n; j++) {
        complex<double> sum(0, 0);
        for (int k = 0; k < n; k++) {
            double angle = -2 * PI * j * k / n;
            sum += a[k] * complex<double>(cos(angle), sin(angle));
        }
        a[j] = sum / sqrt(n);
    }
}

int main() {
    int n = 8;
    double theta = 0.375;
    vector<complex<double>> state(n, 0);
    for (int i = 0; i < n; i++) {
        double angle = 2 * PI * i * theta;
        state[i] = complex<double>(cos(angle), sin(angle)) / sqrt(n);
    }
    qft_inv(state);
    for (int i = 0; i < n; i++) {
        cout << i << ": " << norm(state[i]) << endl;
    }
    return 0;
}
