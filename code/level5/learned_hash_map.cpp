#include<bits/stdc++.h>
using namespace std;

struct LearnedHash {
    double slope, intercept;
    int num_buckets;
    vector<vector<pair<int, int>>> buckets;

    LearnedHash(int n) : num_buckets(n) {
        buckets.resize(num_buckets);
    }

    void train(const vector<int>& keys) {
        int n = keys.size();
        if(n < 2) { slope = 0; intercept = 0; return; }
        double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
        for(int i = 0; i < n; i++) {
            sum_x += keys[i];
            sum_y += i;
            sum_xy += (double)keys[i] * i;
            sum_xx += (double)keys[i] * keys[i];
        }
        slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
        intercept = (sum_y - slope * sum_x) / n;
    }

    int get_pos(int key) {
        int p = (int)(slope * key + intercept);
        return max(0, min(num_buckets - 1, p));
    }

    void insert(int key, int val) {
        buckets[get_pos(key)].push_back({key, val});
    }

    int query(int key) {
        for(auto& p : buckets[get_pos(key)]) if(p.first == key) return p.second;
        return -1;
    }
};

int main() {
    vector<int> keys = {10, 20, 30, 40, 50};
    LearnedHash lh(10);
    lh.train(keys);
    for(int k : keys) lh.insert(k, k * 10);
    cout << lh.query(30) << endl;
    return 0;
}
