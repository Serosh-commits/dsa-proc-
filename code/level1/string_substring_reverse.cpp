#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "hello world";
    cout << s.substr(0, 5) << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
