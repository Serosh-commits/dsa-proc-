#include<bits/stdc++.h>
using namespace std;

struct HashTable {
    int size; vector<int> table;
    HashTable(int s) : size(s), table(s, -1) {}
    int h1(int k) { return k % size; }
    int h2(int k) { return 5 - (k % 5); }
    void insert(int key) {
        for(int i = 0; i < size; i++) {
            int idx = (h1(key) + i * h2(key)) % size;
            if(table[idx] == -1) { table[idx] = key; return; }
        }
    }
};

int main() {
    HashTable ht(7); ht.insert(10);
    return 0;
}
