#include<bits/stdc++.h>
#include<thread>
using namespace std;

void searchPart(int arr[], int start, int end, int key, int& result) {
    for(int i = start; i < end; i++) {
        if(arr[i] == key) {
            result = i;
            return;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int res = -1;
    thread t1(searchPart, arr, 0, 4, 6, ref(res));
    thread t2(searchPart, arr, 4, 8, 6, ref(res));
    t1.join(); t2.join();
    cout << res << endl;
    return 0;
}
