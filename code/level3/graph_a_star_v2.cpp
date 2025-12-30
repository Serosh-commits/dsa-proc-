#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, g, h;
    bool operator>(const Node& other) const { return g + h > other.g + other.h; }
};

int main() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, 0, 0, 10});
    cout << "A* simulation." << endl;
    return 0;
}
