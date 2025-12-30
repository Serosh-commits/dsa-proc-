#include <bits/stdc++.h>
using namespace std;

void mergeFiles(const string& f1, const string& f2, const string& out) {
    ifstream in1(f1), in2(f2);
    ofstream of(out);
    int x, y;
    bool has1 = (bool)(in1 >> x), has2 = (bool)(in2 >> y);
    while (has1 && has2) {
        if (x < y) { of << x << "\n"; has1 = (bool)(in1 >> x); }
        else { of << y << "\n"; has2 = (bool)(in2 >> y); }
    }
    while (has1) { of << x << "\n"; has1 = (bool)(in1 >> x); }
    while (has2) { of << y << "\n"; has2 = (bool)(in2 >> y); }
}

void externalSort(const string& input, int chunkSize) {
    ifstream in(input);
    int val, count = 0, fileIdx = 0;
    vector<int> buffer;
    while (in >> val) {
        buffer.push_back(val);
        if (buffer.size() == chunkSize) {
            sort(buffer.begin(), buffer.end());
            ofstream out("temp" + to_string(fileIdx++) + ".txt");
            for (int x : buffer) out << x << "\n";
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        sort(buffer.begin(), buffer.end());
        ofstream out("temp" + to_string(fileIdx++) + ".txt");
        for (int x : buffer) out << x << "\n";
    }

    while (fileIdx > 1) {
        int nextIdx = 0;
        for (int i = 0; i < fileIdx; i += 2) {
            if (i + 1 < fileIdx) {
                mergeFiles("temp" + to_string(i) + ".txt", "temp" + to_string(i + 1) + ".txt", "merged" + to_string(nextIdx++) + ".txt");
            } else {
                rename(("temp" + to_string(i) + ".txt").c_str(), ("merged" + to_string(nextIdx++) + ".txt").c_str());
            }
        }
        for (int i = 0; i < fileIdx; i++) remove(("temp" + to_string(i) + ".txt").c_str());
        for (int i = 0; i < nextIdx; i++) rename(("merged" + to_string(i) + ".txt").c_str(), ("temp" + to_string(i) + ".txt").c_str());
        fileIdx = nextIdx;
    }
}

int main() {
    ofstream out("input.txt");
    for (int i = 0; i < 100; i++) out << rand() % 1000 << "\n";
    out.close();
    externalSort("input.txt", 10);
    return 0;
}
