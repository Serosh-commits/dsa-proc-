#include<bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0, n = heights.size(), i = 0;
    while(i < n) {
        if(s.empty() || heights[s.top()] <= heights[i]) s.push(i++);
        else {
            int tp = s.top(); s.pop();
            maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    while(!s.empty()) {
        int tp = s.top(); s.pop();
        maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - s.top() - 1));
    }
    return maxArea;
}

int main() {
    vector<int> h = {6, 2, 5, 4, 5, 1, 6};
    cout << largestRectangle(h) << endl;
    return 0;
}
