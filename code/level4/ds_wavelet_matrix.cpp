#include <bits/stdc++.h>
using namespace std;

struct WaveletMatrix {
    int height;
    vector<vector<bool>> bits;
    vector<vector<int>> rank;
    vector<int> zero_count;

    WaveletMatrix(vector<int> a) {
        int max_val = *max_element(a.begin(), a.end());
        height = max_val > 0 ? log2(max_val) + 1 : 1;
        bits.resize(height, vector<bool>(a.size()));
        rank.resize(height, vector<int>(a.size() + 1, 0));
        zero_count.resize(height);

        for (int h = height - 1; h >= 0; h--) {
            vector<int> l, r;
            for (int i = 0; i < a.size(); i++) {
                bits[h][i] = (a[i] >> h) & 1;
                rank[h][i + 1] = rank[h][i] + bits[h][i];
                if (bits[h][i]) r.push_back(a[i]);
                else l.push_back(a[i]);
            }
            zero_count[h] = l.size();
            l.insert(l.end(), r.begin(), r.end());
            a = l;
        }
    }

    int access(int i) {
        int res = 0;
        for (int h = height - 1; h >= 0; h--) {
            if (bits[h][i]) {
                res |= (1 << h);
                i = zero_count[h] + rank[h][i];
            } else {
                i = i - rank[h][i];
            }
        }
        return res;
    }
};

int main() {
    vector<int> a = {5, 4, 5, 5, 2, 1, 5, 6};
    WaveletMatrix wm(a);
    cout << wm.access(0) << " " << wm.access(4) << endl;
    return 0;
}
