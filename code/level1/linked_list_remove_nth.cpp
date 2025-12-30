#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* removeNth(Node* head, int n) {
    Node *dummy = new Node(0); dummy->next = head;
    Node *first = dummy, *second = dummy;
    for(int i = 1; i <= n + 1; i++) first = first->next;
    while(first) { first = first->next; second = second->next; }
    second->next = second->next->next;
    return dummy->next;
}

int main() {
    Node* head = new Node(1); head->next = new Node(2);
    head = removeNth(head, 1);
    return 0;
}
