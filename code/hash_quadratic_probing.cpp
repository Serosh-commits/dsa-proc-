#include<bits/stdc++.h>
using namespace std;

struct HashTable {
    int size; vector<int> table;
    HashTable(int s) : size(s), table(s, -1) {}
    void insert(int key) {
        for(int i = 0; i < size; i++) {
            int idx = (key % size + i * i) % size;
            if(table[idx] == -1) { table[idx] = key; return; }
        }
    }
};

int main() {
    HashTable ht(7); ht.insert(10); ht.insert(20);
    return 0;
}
