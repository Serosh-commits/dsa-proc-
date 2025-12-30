#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<int>& arr, int n) { sort(arr.begin(), arr.end()); return arr[n / 2]; }

int selection(vector<int>& arr, int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {
        int n = r - l + 1; vector<int> median((n + 4) / 5); int i;
        for(i = 0; i < n / 5; i++) { vector<int> sub(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + 5); median[i] = findMedian(sub, 5); }
        if(i * 5 < n) { vector<int> sub(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + n % 5); median[i] = findMedian(sub, n % 5); i++; }
        int medOfMed = (i == 1) ? median[i - 1] : selection(median, 0, i - 1, i / 2);
        return medOfMed; 
    }
    return INT_MAX;
}

int main() {
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    selection(arr, 0, arr.size() - 1, 3);
    return 0;
}
