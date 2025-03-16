// Write a C/C++ program to implement NFA that recognise the string "deterministic" using a switch case construct where each case represents a state

#include "bits/stdc++.h"
using namespace std;
#define int int64_t

bool solve (string &s) {
    int n = s.length();
    int state = 0;
    for (char ch : s) {
        switch (state) {
            case 0:
                if (ch == 'd') state = 1;
                else state = -1;
                break;
            case 1:
                if (ch == 'e') state = 2;
                else state = -1;
                break;
            case 2:
                if (ch == 't') state = 3;
                else state = -1;
                break;
            case 3:
                if (ch == 'e') state = 4;
                else state = -1;
                break;
            case 4:
                if (ch == 'r') state = 5;
                else state = -1;
                break;
            case 5:
                if (ch == 'm') state = 6;
                else state = -1;
                break;
            case 6:
                if (ch == 'i') state = 7;
                else state = -1;
                break;
            case 7:
                if (ch == 'n') state = 8;
                else state = -1;
                break;
            case 8:
                if (ch == 'i') state = 9;
                else state = -1;
                break;
            case 9:
                if (ch == 's') state = 10;
                else state = -1;
                break;
            case 10:
                if (ch == 't') state = 11;
                else state = -1;
                break;
            case 11:
                if (ch == 'i') state = 12;
                else state = -1;
                break;
            case 12:
                if (ch == 'c') state = 13;
                else state = -1;
                break;
            case 13:
                state = 13;
                break;
        }
    }
    return state == 13;
}

signed main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        if (solve(s)) cout << "String is accepted" << '\n';
        else cout << "String is rejetced" << '\n';
    }
}