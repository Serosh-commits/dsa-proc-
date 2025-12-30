#include <bits/stdc++.h>
using namespace std;

struct QState {
    vector<double> amplitudes;
    QState(int n) : amplitudes(n, 1.0 / sqrt(n)) {}
};

void applyOracle(QState& state, const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            state.amplitudes[i] *= -1;
        }
    }
}

void applyDiffusion(QState& state) {
    int n = state.amplitudes.size();
    double avg = 0;
    for (double a : state.amplitudes) avg += a;
    avg /= n;
    for (double& a : state.amplitudes) a = 2 * avg - a;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};
    int target = 50;
    int n = arr.size();
    QState state(n);

    int iterations = round(M_PI / 4 * sqrt(n));
    for (int i = 0; i < iterations; i++) {
        applyOracle(state, arr, target);
        applyDiffusion(state);
    }

    cout << "Quantum Search Probabilities:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index " << i << " (Value " << arr[i] << "): " 
             << fixed << setprecision(4) << state.amplitudes[i] * state.amplitudes[i] << endl;
    }

    return 0;
}
