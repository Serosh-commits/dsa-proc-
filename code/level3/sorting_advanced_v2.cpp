#include<bits/stdc++.h>
using namespace std;

void externalMergeSort(string input_file, string output_file) {
    ifstream in(input_file);
    vector<int> buffer;
    int val, file_count = 0;
    while(in >> val) {
        buffer.push_back(val);
        if(buffer.size() == 100) {
            sort(buffer.begin(), buffer.end());
            ofstream out("temp_" + to_string(file_count++) + ".txt");
            for(int x : buffer) out << x << " ";
            buffer.clear();
        }
    }
}

void timSortGallop(vector<int>& arr, int n) {
    int RUN = 32;
    for(int i = 0; i < n; i += RUN) {
        for(int j = i + 1; j < min(i + RUN, n); j++) {
            int temp = arr[j], k = j - 1;
            while(k >= i && arr[k] > temp) {
                arr[k+1] = arr[k];
                k--;
            }
            arr[k+1] = temp;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    timSortGallop(arr, 6);
    for(int x : arr) cout << x << " ";
    return 0;
}
