#include <bits/stdc++.h>
using namespace std;

struct BinomialNode {
    int key, degree;
    BinomialNode *parent, *child, *sibling;
    BinomialNode(int k) : key(k), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {}
};

struct BinomialHeap {
    BinomialNode* head;
    BinomialHeap() : head(nullptr) {}

    BinomialNode* mergeTrees(BinonacciNode* b1, BinomialNode* b2) {
        if (b1->key > b2->key) swap(b1, b2);
        b2->parent = b1;
        b2->sibling = b1->child;
        b1->child = b2;
        b1->degree++;
        return b1;
    }

    BinomialNode* unionHeaps(BinomialNode* h1, BinomialNode* h2) {
        if (!h1) return h2;
        if (!h2) return h1;
        BinomialNode *res = nullptr, **curr = &res;
        while (h1 && h2) {
            if (h1->degree <= h2->degree) { *curr = h1; h1 = h1->sibling; }
            else { *curr = h2; h2 = h2->sibling; }
            curr = &((*curr)->sibling);
        }
        *curr = h1 ? h1 : h2;

        BinomialNode *prev = nullptr, *x = res, *next = res->sibling;
        while (next) {
            if (x->degree != next->degree || (next->sibling && next->sibling->degree == x->degree)) {
                prev = x; x = next;
            } else {
                if (x->key <= next->key) {
                    x->sibling = next->sibling;
                    mergeTrees(x, next);
                } else {
                    if (!prev) res = next;
                    else prev->sibling = next;
                    mergeTrees(next, x);
                    x = next;
                }
            }
            next = x->sibling;
        }
        return res;
    }

    void insert(int k) {
        head = unionHeaps(head, new BinomialNode(k));
    }

    int extractMin() {
        if (!head) return -1;
        BinomialNode *minNode = head, *prevMin = nullptr, *prev = head, *curr = head->sibling;
        while (curr) {
            if (curr->key < minNode->key) { minNode = curr; prevMin = prev; }
            prev = curr; curr = curr->sibling;
        }
        if (!prevMin) head = minNode->sibling;
        else prevMin->sibling = minNode->sibling;

        BinomialNode *newHead = nullptr, *child = minNode->child;
        while (child) {
            BinomialNode* next = child->sibling;
            child->sibling = newHead;
            child->parent = nullptr;
            newHead = child;
            child = next;
        }
        head = unionHeaps(head, newHead);
        int res = minNode->key;
        delete minNode;
        return res;
    }
};

int main() {
    BinomialHeap h;
    h.insert(10); h.insert(5); h.insert(20);
    cout << h.extractMin() << " " << h.extractMin() << endl;
    return 0;
}
