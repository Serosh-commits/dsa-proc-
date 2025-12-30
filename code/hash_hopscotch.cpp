#include <bits/stdc++.h>
using namespace std;

struct HopscotchHash {
    static const int H = 4;
    struct Node {
        int key;
        uint32_t hop;
        bool active;
        Node() : key(-1), hop(0), active(false) {}
    };
    int size;
    vector<Node> table;
    HopscotchHash(int n) : size(n), table(n) {}

    int hash(int key) { return key % size; }

    void insert(int key) {
        int h = hash(key);
        int empty = -1;
        for (int i = 0; i < size; i++) {
            int idx = (h + i) % size;
            if (!table[idx].active) {
                empty = idx;
                break;
            }
        }
        if (empty == -1) return;

        while (true) {
            int dist = (empty - h + size) % size;
            if (dist < H) {
                table[empty].key = key;
                table[empty].active = true;
                table[h].hop |= (1 << dist);
                return;
            }
            bool moved = false;
            for (int i = H - 1; i > 0; i--) {
                int prev = (empty - i + size) % size;
                for (int j = 0; j < i; j++) {
                    if (table[prev].hop & (1 << j)) {
                        int target = (prev + j) % size;
                        table[empty] = table[target];
                        table[prev].hop &= ~(1 << j);
                        table[prev].hop |= (1 << i);
                        empty = target;
                        moved = true;
                        break;
                    }
                }
                if (moved) break;
            }
            if (!moved) return;
        }
    }

    bool find(int key) {
        int h = hash(key);
        for (int i = 0; i < H; i++) {
            if (table[h].hop & (1 << i)) {
                if (table[(h + i) % size].key == key) return true;
            }
        }
        return false;
    }
};

int main() {
    HopscotchHash hh(10);
    hh.insert(5);
    hh.insert(15);
    cout << hh.find(5) << " " << hh.find(15) << " " << hh.find(25) << endl;
    return 0;
}
