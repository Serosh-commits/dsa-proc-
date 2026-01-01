#include<bits/stdc++.h>
using namespace std;

struct LearnedIndexSim {
    double slope, intercept;
    void train(vector<int>& keys) {
        int n = keys.size();
        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
        for(int i = 0; i < n; i++) {
            sumX += keys[i]; sumY += i;
            sumXY += (double)keys[i] * i; sumX2 += (double)keys[i] * keys[i];
        }
        slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
        intercept = (sumY - slope * sumX) / n;
    }
    int predict(int key) { return (int)(slope * key + intercept); }
};

int main() {
    vector<int> keys = {10, 20, 30, 40, 50};
    LearnedIndexSim li; li.train(keys);
    cout << li.predict(30) << endl;
    return 0;
}
