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

%token SI
%token ALORS
%token SINON
%token FINSI
%token REPETER
%token FINREPETER
%token FOR
%token FINPOUR

%%

int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();
  return 0;
}