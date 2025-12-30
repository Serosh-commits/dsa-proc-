#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* npx;
    Node(int d) : data(d), npx(NULL) {}
};

Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->npx = head;
    if(head) head->npx = XOR(newNode, head->npx);
    head = newNode;
}

int main() {
    Node* head = NULL;
    insert(head, 10);
    insert(head, 20);
    return 0;
}
