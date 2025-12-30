#include<bits/stdc++.h>
using namespace std;

struct Node {
    int numElements;
    int elements[4];
    Node* next;
    Node() : numElements(0), next(NULL) {}
};

int main() {
    Node* head = new Node();
    head->elements[head->numElements++] = 1;
    return 0;
}
