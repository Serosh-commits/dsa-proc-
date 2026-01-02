#include <bits/stdc++.h>
using namespace std;

struct QuantumHeap {
    priority_queue<pair<double, int>> pq;
    void push(int val, double amp) { pq.push({amp, val}); }
    int pop() {
        int res = pq.top().second;
        pq.pop();
        return res;
    }
};

int main() {
    QuantumHeap qh;
    qh.push(10, 0.8);
    qh.push(20, 0.2);
    cout << qh.pop() << endl;
    return 0;
}
