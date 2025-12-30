#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

Node* merge(Node* l1, Node* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

int main() {
    Node* l1 = new Node(1); l1->next = new Node(3);
    Node* l2 = new Node(2); l2->next = new Node(4);
    Node* merged = merge(l1, l2);
    return 0;
}
