#include<bits/stdc++.h>
using namespace std;

struct HashOpenAddressing {
    int *table, capacity, size;
    HashOpenAddressing(int c) { capacity = c; size = 0; table = new int[capacity]; memset(table, -1, sizeof(int)*capacity); }
    void insert(int key) {
        int index = key % capacity;
        while(table[index] != -1) index = (index + 1) % capacity;
        table[index] = key; size++;
    }
};

int main() {
    HashOpenAddressing h(7);
    h.insert(10);
    return 0;
}
