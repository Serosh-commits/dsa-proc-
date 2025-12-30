#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size(), ans = 0;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && height[i] > height[st.top()]) {
            int top = st.top(); st.pop();
            if(st.empty()) break;
            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(h) << endl;
    return 0;
}
