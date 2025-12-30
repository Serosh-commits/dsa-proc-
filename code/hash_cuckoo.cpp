#include <bits/stdc++.h>
using namespace std;

struct CuckooHash {
    int size;
    vector<int> t1, t2;
    CuckooHash(int n) : size(n), t1(n, -1), t2(n, -1) {}

    int h1(int key) { return key % size; }
    int h2(int key) { return (key / size) % size; }

    void insert(int key, int cnt = 0) {
        if (cnt > size) {
            rehash();
            insert(key);
            return;
        }
        int pos1 = h1(key);
        if (t1[pos1] == -1) {
            t1[pos1] = key;
            return;
        }
        int old = t1[pos1];
        t1[pos1] = key;
        int pos2 = h2(old);
        if (t2[pos2] == -1) {
            t2[pos2] = old;
            return;
        }
        int old2 = t2[pos2];
        t2[pos2] = old;
        insert(old2, cnt + 1);
    }

    void rehash() {
        vector<int> old1 = t1, old2 = t2;
        size *= 2;
        t1.assign(size, -1);
        t2.assign(size, -1);
        for (int x : old1) if (x != -1) insert(x);
        for (int x : old2) if (x != -1) insert(x);
    }

    bool find(int key) {
        return t1[h1(key)] == key || t2[h2(key)] == key;
    }
};

int main() {
    CuckooHash ch(7);
    ch.insert(10);
    ch.insert(20);
    ch.insert(30);
    cout << ch.find(20) << " " << ch.find(15) << endl;
    return 0;
}
