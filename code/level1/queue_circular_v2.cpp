#include<bits/stdc++.h>
using namespace std;

struct CircularQueue {
    int *arr, front, rear, size, capacity;
    CircularQueue(int c) {
        capacity = c; front = size = 0; rear = capacity - 1;
        arr = new int[capacity];
    }
    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }
    void enqueue(int item) {
        if(isFull()) return;
        rear = (rear + 1) % capacity; arr[rear] = item; size++;
    }
    int dequeue() {
        if(isEmpty()) return INT_MIN;
        int item = arr[front]; front = (front + 1) % capacity; size--;
        return item;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    return 0;
}
