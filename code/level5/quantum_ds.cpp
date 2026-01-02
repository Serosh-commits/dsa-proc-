#include<bits/stdc++.h>
using namespace std;

struct QuantumHeap {
    vector<int> data;
    int grover_search(int target) {
        int n = data.size();
        int iterations = sqrt(n);
        for(int i = 0; i < iterations; i++) {
            if(data[i] == target) return i;
        }
        return -1;
    }
};

int main() {
    QuantumHeap qh;
    qh.data = {1, 5, 3, 9, 2, 7, 4};
    cout << qh.grover_search(9) << endl;
    return 0;
}
