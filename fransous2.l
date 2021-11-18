%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "fransous2.bison.hpp"
%}

%% 

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? {  yylval.nombre = atof(yytext); return NUM; }
\n     {  return '\n'; }

\r     { }
" "    { }
\t     { }
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
[Ff][Oo][Rr] {return FOR;}
vrai {return VRAI;}
faux {return FAUX;}

plus    { return '+'; }
moins   { return '-'; }
fois    { return '*'; }
divise  { return '/'; } /*Peut-être penser à un autre nom pour l'opérateur*/

[A-Za-z_][A-Za-z_0-9]* { strcpy( yylval.texte, yytext) ;  return TEXT; }

\+     {  return yytext[0];  }  // la même chose que return '+'  
"-"    {  return '-'; }
"*"    {  return '*'; }
"/"    {  return '/'; }
"="|"<-"|"est"    {  return '='; }
\(     {  return '('; }
\)     {  return ')'; }
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%