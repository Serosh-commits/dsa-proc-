#include <bits/stdc++.h>
using namespace std;

struct NeuralIndex {
    vector<int> data;
    NeuralIndex(vector<int> a) : data(a) { sort(data.begin(), data.end()); }
    int predict(int key) {
        auto it = lower_bound(data.begin(), data.end(), key);
        return it - data.begin();
    }
};

int main() {
    vector<int> a = {10, 20, 30, 40, 50};
    NeuralIndex ni(a);
    cout << ni.predict(30) << endl;
    return 0;
}
