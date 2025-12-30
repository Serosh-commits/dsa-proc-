#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;
public:
    CircularQueue(int s) : size(s), front(-1), rear(-1) {
        arr = new int[s];
    }
    void enqueue(int x) {
        if((rear + 1) % size == front) return;
        if(front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
    int dequeue() {
        if(front == -1) return -1;
        int res = arr[front];
        if(front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return res;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl;
    return 0;
}
