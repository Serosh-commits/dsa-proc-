#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> res = nextGreater(arr);
    for(int x : res) cout << x << " ";
    return 0;
}
