#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct CircularQueue {
    T* arr;
    int front, rear, size, capacity;

    CircularQueue(int cap = 4) : capacity(cap), front(0), rear(0), size(0) {
        arr = new T[capacity];
    }

    ~CircularQueue() { delete[] arr; }

    void resize() {
        int new_capacity = capacity * 2;
        T* new_arr = new T[new_capacity];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[(front + i) % capacity];
        }
        delete[] arr;
        arr = new_arr;
        front = 0;
        rear = size;
        capacity = new_capacity;
    }

    void push(T val) {
        if (size == capacity) resize();
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }

    void pop() {
        if (size == 0) return;
        front = (front + 1) % capacity;
        size--;
    }

    T get_front() {
        if (size == 0) throw runtime_error("Queue is empty");
        return arr[front];
    }

    bool empty() { return size == 0; }
};

int main() {
    CircularQueue<int> q;
    for (int i = 1; i <= 10; i++) q.push(i);
    while (!q.empty()) {
        cout << q.get_front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
