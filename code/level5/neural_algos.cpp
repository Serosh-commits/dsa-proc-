#include<bits/stdc++.h>
using namespace std;

struct NeuralSort {
    vector<double> weights;
    void train(int n) {
        weights.resize(n);
        for(int i = 0; i < n; i++) weights[i] = (double)rand() / RAND_MAX;
    }
    vector<int> predict(vector<int>& arr) {
        int n = arr.size();
        vector<pair<double, int>> scored;
        for(int i = 0; i < n; i++) scored.push_back({arr[i] * weights[i], arr[i]});
        sort(scored.begin(), scored.end());
        vector<int> res;
        for(auto& p : scored) res.push_back(p.second);
        return res;
    }
};

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    NeuralSort ns;
    ns.train(6);
    vector<int> res = ns.predict(arr);
    for(int x : res) cout << x << " ";
    return 0;
}
