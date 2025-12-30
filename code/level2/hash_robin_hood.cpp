#include <bits/stdc++.h>
using namespace std;

struct RobinHoodHash {
    struct Node {
        int key, psl;
        bool active;
        Node() : key(-1), psl(0), active(false) {}
    };
    int size;
    vector<Node> table;
    RobinHoodHash(int n) : size(n), table(n) {}

    int hash(int key) { return key % size; }

    void insert(int key) {
        int pos = hash(key);
        Node curr;
        curr.key = key;
        curr.psl = 0;
        curr.active = true;

        for (int i = 0; i < size; i++) {
            int idx = (pos + i) % size;
            if (!table[idx].active) {
                table[idx] = curr;
                return;
            }
            if (curr.psl > table[idx].psl) {
                swap(curr, table[idx]);
            }
            curr.psl++;
        }
    }

    bool find(int key) {
        int pos = hash(key);
        for (int i = 0; i < size; i++) {
            int idx = (pos + i) % size;
            if (!table[idx].active) return false;
            if (table[idx].key == key) return true;
            if (i > table[idx].psl) return false;
        }
        return false;
    }
};

int main() {
    RobinHoodHash rh(10);
    rh.insert(5);
    rh.insert(15);
    rh.insert(25);
    cout << rh.find(15) << " " << rh.find(10) << endl;
    return 0;
}
