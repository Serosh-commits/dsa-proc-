#include<bits/stdc++.h>
using namespace std;

struct HashTable {
    int size, count; vector<list<int>> table;
    HashTable(int s) : size(s), count(0), table(s) {}
    void insert(int key) {
        if((double)count / size > 0.7) rehash();
        table[key % size].push_back(key); count++;
    }
    void rehash() {
        int oldSize = size; size *= 2;
        vector<list<int>> oldTable = table;
        table.assign(size, list<int>()); count = 0;
        for(auto& l : oldTable) for(int x : l) insert(x);
    }
};

int main() {
    HashTable ht(2); ht.insert(1); ht.insert(2); ht.insert(3);
    return 0;
}
