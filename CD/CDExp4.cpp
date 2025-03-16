#include <bits/stdc++.h>
using namespace std;

enum TokenType { VARIABLE, ARITHMETIC_PL, L_PARENTHESIS, R_PARENTHESIS, STRING, WHITE_SPACE, COMMA, SEMICOLON, ERROR };

bool is_variable_char(char ch) { return isalpha(ch) || ch == '_'; }
bool is_digit(char ch) { return isdigit(ch); }
bool is_white_space(char ch) { return ch == ' ' || ch == '\n'; }

TokenType match(string &s, int &i, vector<int> &literals) {
    if (is_variable_char(s[i])) {
        while (i < s.length() && (is_variable_char(s[i]) || is_digit(s[i]))) i++;
        return VARIABLE;
    }
    if (s[i] == '+') return i++, ARITHMETIC_PL;
    if (s[i] == '(') return i++, L_PARENTHESIS;
    if (s[i] == ')') return i++, R_PARENTHESIS;
    if (s[i] == ',') return i++, COMMA;
    if (s[i] == ';') return i++, SEMICOLON;
    if (s[i] == '"') {
        int start = ++i;
        while (i < s.length() && s[i] != '"') i++;
        if (i == s.length()) return ERROR;
        literals.push_back(start);
        return i++, STRING;
    }
    if (is_white_space(s[i])) {
        while (i < s.length() && is_white_space(s[i])) i++;
        return WHITE_SPACE;
    }
    return ERROR;
}

void lexical_analyzer(string &s, vector<TokenType> &tokens, vector<int> &literals) {
    int i = 0;
    while (i < s.length()) {
        TokenType token = match(s, i, literals);
        if (token == ERROR) { cerr << "Unknown token encountered. Terminating." << endl; exit(1); }
        tokens.push_back(token);
    }
}

void display(TokenType token, vector<int> &literals, string &s, int &var_count, int &lit_count) {
    switch (token) {
        case VARIABLE: cout << "<id," << var_count++ << ">"; break;
        case ARITHMETIC_PL: cout << "<arith,PL>"; break;
        case L_PARENTHESIS: cout << "<paren,s_open>"; break;
        case R_PARENTHESIS: cout << "<paren,s_close>"; break;
        case STRING: cout << "<string, \"" << s.substr(literals[lit_count], s.find('"', literals[lit_count]) - literals[lit_count]) << "\">"; lit_count++; break;
        case COMMA: cout << "<punc,COMMA>"; break;
        case SEMICOLON: cout << "<punc,SEMICOLON>"; break;
        case WHITE_SPACE: cout << "<whitespace>"; break;
        case ERROR: cerr << "Error occurred, terminating" << endl; exit(1);
    }
}

int main() {
    string s = "printf(  \"the addition of two numbers is %d\", a+b);";
    vector<TokenType> tokens;
    vector<int> literals;
    lexical_analyzer(s, tokens, literals);
    
    cout << "Number of tokens: " << tokens.size() << endl;
    cout << "Tokens:-\n";
    int var_count = 0, lit_count = 0;
    for (TokenType token : tokens) { display(token, literals, s, var_count, lit_count); cout << endl; }
    return 0;
}