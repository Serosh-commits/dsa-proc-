#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    return 0;
}
