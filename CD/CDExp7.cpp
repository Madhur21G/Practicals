// Aim:- Write a program to process the input stream while(abc == 32) and issue token for the same. Create nfa for the category
// and parallely navigate between them in correct order.

#include "bits/stdc++.h"
using namespace std;

enum TokenType { VARIABLE, NUMBER, L_PAREN, R_PAREN, WHILE, RELOP_EQ, UNMATCH };

bool is_variable_char(char ch) {
    return ch == '_' || isalpha(ch);
}

bool is_digit(char ch) {
    return isdigit(ch);
}

TokenType nfa_while(string& input, int& lexeme_begin) {
    int state = 0, i = lexeme_begin;
    while (state != -1) {
        switch (state) {
            case 0: state = (input[i++] == 'w') ? 1 : -1; break;
            case 1: state = (input[i++] == 'h') ? 2 : -1; break;
            case 2: state = (input[i++] == 'i') ? 3 : -1; break;
            case 3: state = (input[i++] == 'l') ? 4 : -1; break;
            case 4: state = (input[i++] == 'e') ? 5 : -1; break;
            case 5: 
                if (!is_variable_char(input[i]) && !is_digit(input[i])) {
                    lexeme_begin = i;
                    return WHILE;
                }
                state = -1;
        }
    }
    return UNMATCH; 
}

TokenType nfa_var(string& input, int& lexeme_begin) {
    int i = lexeme_begin;
    if (is_variable_char(input[i])) {
        while (is_variable_char(input[++i]) || is_digit(input[i]));
        lexeme_begin = i;
        return VARIABLE;
    }
    return UNMATCH;
}

TokenType nfa_relop(string& input, int& lexeme_begin) {
    int i = lexeme_begin;
    if (input[i] == '=' && input[i + 1] == '=') {
        lexeme_begin = i + 2;
        return RELOP_EQ;
    }
    return UNMATCH;
}

TokenType nfa_number(string& input, int& lexeme_begin, int literals[], int& lit_count) {
    int state = 0, i = lexeme_begin;
    while (state != -1) {
        switch (state) {
            case 0: state = (is_digit(input[i])) ? 1 : -1; break;
            case 1: state = (is_digit(input[++i])) ? 1 : 2; break;
            case 2:
                literals[lit_count++] = lexeme_begin;
                lexeme_begin = i + 1;
                return NUMBER;
        }
    }
    return UNMATCH;
}

TokenType nfa_paren(string& input, int& lexeme_begin) {
    if (input[lexeme_begin] == '(') return (lexeme_begin++, L_PAREN);
    if (input[lexeme_begin] == ')') return (lexeme_begin++, R_PAREN);
    return UNMATCH;
}

void lexical_analyzer(string& input, TokenType tokens[], int& token_count, int literals[], int& lit_count) {
    int lexeme_begin = 0;
    while (input[lexeme_begin] != '\0') {
        TokenType token;
        if ((token = nfa_while(input, lexeme_begin)) != UNMATCH ||
            (token = nfa_var(input, lexeme_begin)) != UNMATCH ||
            (token = nfa_relop(input, lexeme_begin)) != UNMATCH ||
            (token = nfa_number(input, lexeme_begin, literals, lit_count)) != UNMATCH ||
            (token = nfa_paren(input, lexeme_begin)) != UNMATCH) {
            tokens[token_count++] = token;
            continue;
        }
        cout << "Unexpected token" << endl;
        exit(1);
    }
}

void display(TokenType token, int literals[], string& input, int& lit_count) {
    static int count = 0;
    switch (token) {
        case WHILE: cout << "<while>"; break;
        case L_PAREN: cout << "<paren, S_OP>"; break;
        case R_PAREN: cout << "<paren, S_CL>"; break;
        case VARIABLE: cout << "<id," << count++ << ">"; break;
        case NUMBER: {
            cout << "<num,";
            int start = literals[lit_count++];
            while (is_digit(input[start])) cout << input[start++];
            cout << ">";
            break;
        }
        case RELOP_EQ: cout << "<relop,EQ>"; break;
        case UNMATCH: break;
    }
}

int main() {
    string input = "while(abc==32)";
    TokenType tokens[1000];
    int literals[1000], token_count = 0, literal_count = 0;
    lexical_analyzer(input, tokens, token_count, literals, literal_count);
    int count = 0;
    for (int i = 0; i < token_count; i++) display(tokens[i], literals, input, count);
    cout << endl;
    return 0;
}