#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = head;
    cout << hasCycle(head) << endl;
    return 0;
}
