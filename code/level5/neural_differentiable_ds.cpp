#include <bits/stdc++.h>
using namespace std;

struct NeuralStack {
    vector<double> stack;
    void push(double val, double strength) {
        stack.push_back(val * strength);
    }
    double pop() {
        double res = stack.back();
        stack.pop_back();
        return res;
    }
};

int main() {
    NeuralStack ns;
    ns.push(1.0, 0.9);
    cout << ns.pop() << endl;
    return 0;
}
