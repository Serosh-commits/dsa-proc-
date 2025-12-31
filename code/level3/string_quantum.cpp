#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<double> amp(n, 1.0 / sqrt(n));
    int target = 1;
    for (int i = 0; i < 2; i++) {
        amp[target] *= -1;
        double avg = 0;
        for (double a : amp) avg += a;
        avg /= n;
        for (double& a : amp) a = 2 * avg - a;
    }
    for (int i = 0; i < n; i++) cout << i << ": " << amp[i] * amp[i] << endl;
    return 0;
}
