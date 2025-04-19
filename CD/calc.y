%{ 
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(const char *s);
    int flag = 0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

input:
      /* empty */
    | input line
    ;

line:
      '\n'
    | expr '\n'   { printf("Result = %d\n", $1); }
    ;

expr:
      expr '+' expr  { $$ = $1 + $3; }
    | expr '-' expr  { $$ = $1 - $3; }
    | expr '*' expr  { $$ = $1 * $3; }
    | expr '/' expr  { $$ = $1 / $3; }
    | expr '%' expr  { $$ = $1 % $3; }
    | '(' expr ')'   { $$ = $2; }
    | NUMBER         { $$ = $1; }
    ;

%%

int main(void) {
    printf("Enter expression: ");
    yyparse();
    if (flag == 0)
        printf("Entered arithmetic expression is valid\n");
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    flag = 1;
}
