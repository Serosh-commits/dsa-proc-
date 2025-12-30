#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr) { next = curr->next; curr->next = prev; prev = curr; curr = next; }
    return prev;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head = reverse(head);
    return 0;
}
