#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Stack {
    T* arr;
    int top_idx, capacity;

    Stack(int cap = 4) : capacity(cap), top_idx(-1) {
        arr = new T[capacity];
    }

    ~Stack() { delete[] arr; }

    void resize() {
        capacity *= 2;
        T* new_arr = new T[capacity];
        for (int i = 0; i <= top_idx; i++) new_arr[i] = arr[i];
        delete[] arr;
        arr = new_arr;
    }

    void push(T val) {
        if (top_idx == capacity - 1) resize();
        arr[++top_idx] = val;
    }

    void pop() {
        if (top_idx >= 0) top_idx--;
    }

    T top() {
        if (top_idx < 0) throw runtime_error("Stack is empty");
        return arr[top_idx];
    }

    bool empty() { return top_idx == -1; }
};

int main() {
    Stack<int> s;
    for (int i = 1; i <= 10; i++) s.push(i);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
