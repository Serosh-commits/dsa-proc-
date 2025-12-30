#include<bits/stdc++.h>
using namespace std;

struct HashTable {
    int BUCKET;
    list<int> *table;
    HashTable(int b) { BUCKET = b; table = new list<int>[BUCKET]; }
    void insert(int key) { int index = key % BUCKET; table[index].push_back(key); }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    return 0;
}
