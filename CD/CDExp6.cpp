// Aim:- Writ a program to serially naviagte through Relop and num lexical categories and process the input string
// Sample case:
// Case1: >=3 Expected Output: <RELOP, GE> <num, 3>
// Case2: >=34 Expected Output: <RELOP, GE> <num, 34>
// Case3: <=4>3 Expected Output: <RELOP, LE> <num, 4> <RELOP, GT> <num, 3>
// Case4: abc>=4 Expected Output: <ID,1> <RELOP, GE> <num, 4>

#include "bits/stdc++.h"
using namespace std;

class Token {
public:
    string tname;
    string attri;
    Token(string name) : tname(name), attri("") {}
};

string s;
string::iterator lexem, fwd;

Token *getToken(string name) { return new Token(name); }

void fail(bool &check) {
    check = false;
    fwd = lexem;
}

void retract() { --fwd; }

Token *getNum() {
    int state = 0;
    string num;
    bool check = true;
    Token *t = getToken("NUM");
    while (check) {
        char ch;
        switch (state) {
        case 0:
            ch = *(fwd++);
            if (isdigit(ch)) {
                num += ch;
                state = 1;
            }
            else fail(check);
            break;
        case 1:
            ch = *(fwd++);
            if (isdigit(ch)) num += ch;
            else state = 2;
            break;
        case 2:
            retract();
            t->attri = num;
            return t;
        default:
            break;
        }
    }
    return t;
}

Token *getID() {
    int state = 0;
    string id;
    bool check = true;
    Token *t = getToken("ID");
    while (check) {
        char ch;
        switch (state) {
        case 0:
            ch = *(fwd++);
            if (isalpha(ch)) {
                id += ch;
                state = 1;
            } else fail(check);
            break;
        case 1:
            ch = *(fwd++);
            if (isalnum(ch)) id += ch;
            else state = 2;
            break;
        case 2:
            retract();
            t->attri = "1";
            return t;
        default:
            break;
        }
    }
    return t;
}

Token *getRelop() {
    int state = 0;
    bool check = true;
    Token *t = getToken("RELOP");
    while (check) {
        char ch;
        switch (state) {
        case 0:
            ch = *(fwd++);
            if (ch == '<') state = 1;
            else if (ch == '>') state = 2;
            else if (ch == '=') state = 3;
            else fail(check);
            break;
        case 1:
            ch = *(fwd++);
            if (ch == '=') state = 4;
            else if (ch == '>') state = 5;
            else state = 6;
            break;
        case 2:
            ch = *(fwd++);
            if (ch == '=') state = 7;
            else state = 8;
            break;
        case 3:
            t->attri = "EQ";
            return t;
        case 4:
            t->attri = "LE";
            return t;
        case 5:
            t->attri = "NE";
            return t;
        case 6:
            retract();
            t->attri = "LT";
            return t;
        case 7:
            t->attri = "GE";
            return t;
        case 8:
            retract();
            t->attri = "GT";
            return t;
        default:
            break;
        }
    }
    return t;
}

signed main() {
    int tc; cin >> tc;
    while (tc--) {
        cout << "Enter Input String: ";
        cin >> s;
        lexem = s.begin();
        fwd = s.begin();
        while (lexem != s.end()) {
            Token *t = getID();
            if (!t->attri.empty()) {
                lexem = fwd;
                cout << "<" << t->tname << ", " << t->attri << "> ";
            } 
            else {
                delete t;
                t = getNum();
                if (!t->attri.empty()) {
                    lexem = fwd;
                    cout << "<" << t->tname << ", " << t->attri << "> ";
                } 
                else {
                    delete t;
                    t = getRelop();
                    if (!t->attri.empty()) {
                        lexem = fwd;
                        cout << "<" << t->tname << ", " << t->attri << "> ";
                    } 
                    else {
                        cout << "<OTHER> ";
                        ++lexem;
                        ++fwd;
                    }
                }
            }
            delete t;
        }
        cout << '\n';
    }
    return 0;
}