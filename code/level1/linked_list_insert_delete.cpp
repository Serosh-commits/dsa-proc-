#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

void insert(Node*& head, int d) {
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node*& head, int key) {
    Node *temp = head, *prev = NULL;
    if(temp != NULL && temp->data == key) { head = temp->next; delete temp; return; }
    while(temp != NULL && temp->data != key) { prev = temp; temp = temp->next; }
    if(temp == NULL) return;
    prev->next = temp->next;
    delete temp;
}

int main() {
    Node* head = NULL;
    insert(head, 1);
    deleteNode(head, 1);
    return 0;
}
