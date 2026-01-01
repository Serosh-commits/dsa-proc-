#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<double> amp(n, 1.0 / sqrt(n));
    for (int i = 0; i < n; i++) cout << i << ": " << amp[i] * amp[i] << endl;
    return 0;
}
