%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>

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
%token openFile
%token remove
%token rename
%token tolower

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
expr: SIN '(' expr ')'  { }
     | COS '(' expr ')'  { }
     | TAN '(' expr ')'  { }    
     | exp '('expr ')'   { }
     |sqrt '(' expr ')' { }
     | { }
    

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