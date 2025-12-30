#include<bits/stdc++.h>
using namespace std;

struct alignas(64) CacheAlignedArray {
    int data[16];
};

int main() {
    CacheAlignedArray arr;
    arr.data[0] = 1;
    cout << arr.data[0] << endl;
    return 0;
}
