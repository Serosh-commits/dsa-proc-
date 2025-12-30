#include<bits/stdc++.h>
using namespace std;

struct alignas(64) CacheAligned {
    int data[16];
};

int main() {
    CacheAligned arr[10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 16; j++) {
            arr[i].data[j] = i + j;
        }
    }
    return 0;
}
