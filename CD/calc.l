%{ 
    #include <stdio.h>
    #include <stdlib.h>        /* for atoi() */
    #include "y.tab.h"
%} 

%% 

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[ \t]       /* skip spaces and tabs */;
\n          { return '\n'; }       /* feed newline into the parser */
.           { return yytext[0]; }  /* any other single char */

%%

int yywrap(void) {
    return 1;
}
