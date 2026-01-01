#include<bits/stdc++.h>
using namespace std;

struct LearnedIndex {
    double slope, intercept;
    void train(vector<pair<int, int>>& data) {
        int n = data.size();
        double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
        for(auto& p : data) {
            sumX += p.first; sumY += p.second;
            sumXY += (double)p.first * p.second;
            sumX2 += (double)p.first * p.first;
        }
        slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
        intercept = (sumY - slope * sumX) / n;
    }
    int predict(int key) {
        return (int)(slope * key + intercept);
    }
};

int main() {
    vector<pair<int, int>> data = {{10, 0}, {20, 1}, {30, 2}, {40, 3}};
    LearnedIndex li;
    li.train(data);
    cout << li.predict(25) << endl;
    return 0;
}
