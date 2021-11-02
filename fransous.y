%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <algorithm>

    using namespace std;

    extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);
%}

%token IF
%token THEN
%token ELSE
%token ENDIF
%token FOR
%token ENDFOR
%token PRINT
%token SIN
%token COS
%token TAN
%token SEPARATOR
%token WHILE
%token ENDWHILE
%token SWITCH
%token ENDSWITCH
%token CASE
%token BREAK
%token exp
%token sqrt
%token pow
%token openFileRead
%token remove
%token rename
%token tolower
%token fist
%token last
%token size

%%

lignes:{ }
     | lignes instruction '\n'

separteur : SEPARATOR '\n'


case : {}
        | case CASE condition SEPARATOR instruction BREAK '\n'

alors : {}| ELSE separteur lignes

instruction: {}
        |expr  {}
        |IF condition separteur
        THEN separteur
            lignes
            alors
        ENDIF
        |FOR expr separteur
            lignes
        ENDFOR
        |WHILE condition separteur
            lignes
        ENDWHILE
        |SWITCH var separteur
            case
        ENDSWITCH
expr: SIN '(' expr ')'  {$$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ ); }
     | COS '(' expr ')'  {$$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ );  }
     | TAN '(' expr ')'  {$$ = tan($3); printf ("tan(%g) = %g\n", $3, $$ ); }    
     | exp '('expr ')'   {$$ = exp($3); printf ("exp(%g) = %g\n", $3, $$ ); }
     |sqrt '(' expr ')' { $$ = sqrt($3); printf ("sqrt(%g) = %g\n", $3, $$ ); }
     | { }
    
fonction : openFileRead variable {fopen("$2",r);}
        |openFileWrite variable {fopen("$2",w);}
        |remove variable "dans" variable "jusque" variable {$$=remove($3,$4,$2);} /*Enleve "A" dans camion jusque M*/
        |rename variable "en" variable{$$=rename($2;$3);}
        |tolower variable {$$=tolower($2);}
        |first "de" variable {$$=front($3)}
        |last "de" variable {$$=back($3)}
        |size "de" variable {$$=size($3)}



condition  : {}
var : {}
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();
  return 0;
}