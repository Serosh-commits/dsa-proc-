#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello", s2 = "world";
    cout << s1.length() << endl;
    string s3 = s1 + s2;
    string s4 = s3;
    reverse(s3.begin(), s3.end());
    string pal = "racecar";
    string rev_pal = pal;
    reverse(rev_pal.begin(), rev_pal.end());
    if(pal == rev_pal) cout << "palindrome" << endl;
    return 0;
}
