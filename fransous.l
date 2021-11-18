%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "fransous.bison.hpp"
%}

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? {  yylval.valeur = atof(yytext); return NUM; }
classe [a-zA-Z_-0-9]+ {([\s\S]*?)} { return CLASSE}
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }
\{ {return DACCOLADE}
\} {return FACCOLADE}
[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;  return VAR; }
\+     {  return ADD; }  
"-"    {  return SUB; }
"*"    {  return MULT; }
"/"    {  return DIV; }
"="|"<-"    {  return '='; }
">"    { return SUP; }
\(     {  return '('; }
\)     {  return ')'; }
<<EOF>>  { printf("\nLe programme est correct!\n"); return 0; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
