#include <stdio.h>
#include <stdbool.h>

bool f(const char* input) {
    int curr = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        switch (curr) {
            case 0:
                if (ch == '<') curr = 1;
                else return false;
                break;
            case 1:
                if (ch == '=') curr = 2;
                else return false;
                break;
            case 2:
                if (ch == '4') curr = 3;
                else return false;
                break;
            default:
                return false;
        }
    }
    return curr == 3;
}

int main() {
    char input[10];
    printf("Enter a string to check: ");
    scanf("%9s", input);
    if (f(input)) printf("Accepted: %s\n", input);
    else printf("Rejected: %s\n", input);
    return 0;
}