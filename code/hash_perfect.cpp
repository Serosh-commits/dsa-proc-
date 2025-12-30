#include <bits/stdc++.h>
using namespace std;

struct PerfectHash {
    struct Inner {
        int a, b, m;
        vector<int> table;
        Inner() : a(0), b(0), m(0) {}
        void init(const vector<int>& keys) {
            m = keys.size() * keys.size();
            if (m == 0) return;
            table.assign(m, -1);
            while (true) {
                a = rand() % 1000000006 + 1;
                b = rand() % 1000000007;
                bool collision = false;
                fill(table.begin(), table.end(), -1);
                for (int k : keys) {
                    int h = ((1LL * a * k + b) % 1000000007) % m;
                    if (table[h] != -1) { collision = true; break; }
                    table[h] = k;
                }
                if (!collision) break;
            }
        }
        bool find(int k) {
            if (m == 0) return false;
            int h = ((1LL * a * k + b) % 1000000007) % m;
            return table[h] == k;
        }
    };

    int a, b, m;
    vector<Inner> tables;
    PerfectHash(const vector<int>& keys) {
        m = keys.size();
        tables.resize(m);
        a = rand() % 1000000006 + 1;
        b = rand() % 1000000007;
        vector<vector<int>> buckets(m);
        for (int k : keys) {
            int h = ((1LL * a * k + b) % 1000000007) % m;
            buckets[h].push_back(k);
        }
        for (int i = 0; i < m; i++) tables[i].init(buckets[i]);
    }

    bool find(int k) {
        int h = ((1LL * a * k + b) % 1000000007) % m;
        return tables[h].find(k);
    }
};

int main() {
    vector<int> keys = {10, 20, 30, 40, 50};
    PerfectHash ph(keys);
    cout << ph.find(30) << " " << ph.find(25) << endl;
    return 0;
}
