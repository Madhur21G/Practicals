// Aim - Write a C/C++ program for NFA that accepts the string a*b

#include "bits/stdc++.h"
using namespace std;
#define int int64_t

signed main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        int n = s.length();
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr == 0 && s[i] == 'a') curr = 0;
            else if (curr == 0 && s[i] == 'b') curr = 1;
            else curr = -1;
        }
        if (curr == 1) cout << "String is accepted" << '\n';
        else cout << "String is rejected" << '\n';
    }
}