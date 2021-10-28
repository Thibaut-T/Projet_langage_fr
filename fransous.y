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
%token WHILE
%token PRINT
%token SWITCH
%token SIN
%token COS
%token TAN
%token SEPARATOR
%token WHILE
%token ENDWHILE

%%

lignes:{ }
     | lignes instruction '\n'

separteur : SEPARATOR '\n'

instruction: {}
        |expr  {}
        |IF condition separteur
        THEN separteur
            lignes
        ELSE separteur
            lignes
        ENDIF
        |FOR expr separteur
            lignes
        ENDFOR
        |WHILE condition separteur
            lignes
        ENDWHILE

expr: SIN '(' expr ')'  { }
     | COS '(' expr ')'  { }
     | TAN '(' expr ')'  { }
%%

int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();
  return 0;
}