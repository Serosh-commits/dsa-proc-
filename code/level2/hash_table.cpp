#include<bits/stdc++.h>
using namespace std;

class HashTable {
    int size;
    list<int> *table;
public:
    HashTable(int s) : size(s) {
        table = new list<int>[s];
    }
    void insert(int key) {
        int idx = key % size;
        table[idx].push_back(key);
    }
    bool search(int key) {
        int idx = key % size;
        for(int x : table[idx]) if(x == key) return true;
        return false;
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    cout << ht.search(10) << endl;
    return 0;
}
