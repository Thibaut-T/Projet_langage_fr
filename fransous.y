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
%token REPEAT
%token ENDREPEAT
%token FOR
%token ENDFOR

%%

int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();
  return 0;
}