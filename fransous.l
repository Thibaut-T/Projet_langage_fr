
%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "calculette.bison.hpp"
%}

%%

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? {  yylval.valeur = atof(yytext); return NUM; }
classe [a-zA-Z-_]{1,32}\:(\n((booleen = (true|True|TRUE|false|False|FALSE|0|1))|(nombre = [0-9]+(\.[0-9]*)?)|(texte = [a-zA-Z-_()+* ]{1,32})))+\n[fin] {return classe}
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos { return COS;  }
un      { yylval.valeur = 1. ; return NUM; }
deux    { yylval.valeur = 2. ; return NUM; }
trois   { yylval.valeur = 3. ; return NUM; }
plus    { return '+';}
fois    { return '*'; }

[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.nom, yytext) ;  return VAR; }

\+     {  return yytext[0];  }  // la même chose que return '+'  
"-"    {  return '-'; }
"*"    {  return '*'; }
"/"    {  return '/'; }
"="|"<-"    {  return '='; }
\(     {  return '('; }
\)     {  return ')'; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
