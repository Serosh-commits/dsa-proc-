#include <bits/stdc++.h>
using namespace std;

struct Tape {
    string filename;
    int runs;
};

void polyphaseMerge(vector<Tape>& tapes) {
    while (true) {
        sort(tapes.begin(), tapes.end(), [](const Tape& a, const Tape& b) { return a.runs < b.runs; });
        if (tapes[1].runs == 0) break;
        int mergeCount = tapes[0].runs;
        tapes[2].runs += mergeCount;
        tapes[1].runs -= mergeCount;
        tapes[0].runs = 0;
        cout << "Merged " << mergeCount << " runs into " << tapes[2].filename << endl;
    }
}

int main() {
    vector<Tape> tapes = {{"T1", 13}, {"T2", 8}, {"T3", 0}};
    polyphaseMerge(tapes);
    return 0;
}
