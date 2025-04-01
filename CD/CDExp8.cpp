// Aim:- Write a program to find the first and follow of the non terminals
// S -> AB
// A -> aC
// B -> bC
// C -> E

#include "bits/stdc++.h"
using namespace std;

map<char, set<char>> first, follow;
map<char, vector<string>> prodn;
set<char> nt;

void calcfirst (char ch) {
    if (!nt.count(ch)) {
        first[ch].insert(ch);
        return;
    }
    for (auto x : prodn[ch]) {
        for (int i = 0; i < x.size(); i++) {
            char curr = x[i];
            if (curr == 'E') {
                first[ch].insert('E');
                break;
            }
            calcfirst(curr);
            for (auto c : first[curr]) {
                if (c != 'E') first[ch].insert(c);
            }
            if (first[curr].count('E') == 0) break;
        }
    }
}

void calcfollow(char ch) {
    if (ch == 'S') follow[ch].insert('$');
    for (auto prod : prodn) {
        char nonTerm = prod.first;
        for (auto rule : prod.second) {
            for (int i = 0; i < rule.size(); i++) {
                if (rule[i] == ch) {
                    for (int j = i + 1; j < rule.size(); j++) {
                        char next = rule[j];
                        for (auto z : first[next]) if (z != 'E') follow[ch].insert(z);
                        if (!first[next].count('E')) break;
                    }
                    if (i + 1 == rule.size() || first[rule[i + 1]].count('E')) {
                        if (nonTerm != ch) {
                            calcfollow(nonTerm);
                            for (auto c : follow[nonTerm]) follow[ch].insert(c);
                        }
                    }
                }
            }
        }
    }
}

signed main() {
    prodn['S'] = {"AB"};
    prodn['A'] = {"aC"};
    prodn['B'] = {"bC"};
    prodn['C'] = {"E"};
    for (auto x : prodn)
        nt.insert(x.first);
    for (auto y : nt)
        calcfirst(y);
    cout << "First Sets:" << '\n';
    for (auto x : nt) {
        cout << "First(" << x << ") = { ";
        for (auto ch : first[x]) cout << ch << " ";
        cout << "}" << '\n';
    }
    for (auto y : nt)
        calcfollow(y);
    cout << '\n';
    cout << "Follow Sets:" << '\n';
    for (auto x : nt) {
        cout << "Follow(" << x << ") = { ";
        for (auto ch : follow[x]) cout << ch << " ";
        cout << "}" << '\n';
    }
    return 0;
}