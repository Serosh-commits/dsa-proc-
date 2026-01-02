#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello", p = "ell";
    for (int i = 0; i <= s.size() - p.size(); i++) {
        double score = 0;
        for (int j = 0; j < p.size(); j++) {
            if (s[i + j] == p[j]) score += 1.0;
        }
        if (score / p.size() > 0.8) cout << "Match at " << i << endl;
    }
    return 0;
}
