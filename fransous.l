%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "fransous.bison.hpp"
%}

%%
  \n     {  return '\n'; }
  \r     { }
  " "    { }
  \t     { }

afficher|Afficher|AFFICHER {return print};
choix|Choix|CHOIX {return swicth};
Tant[" "]que|TANT[" "]QUE|tant[" "]que {return while};
si|SI|Si     { return SI; }
alors|ALORS|Alors   { return ALORS; }
sinon|Sinon|SINON   { return SINON; }
fin[" "]du[" "]si| FIN[" "]DU[" "]SI|Fin[" "]du[" "]si|Fin[" "]Du[" "]Si  { return FINSI; }
repeter|REPETER|Repeter { return REPETER; }
fin[" "]du[" "]repeter|FIN[" "]DU[" "]REPETER|Fin[" "]Du[" "]Repeter { return FINREPETER;}
pour|POUR|Pour { return FOR;}
fin [" "]du[" "]pour|FIN[" "]DU[" "]POUR|Fin[" "]Du[" "]Pour { return FINPOUR;}
  

  <<EOF>> { printf ("Le programme est correct.\n"); return 0;}
  .      {  printf ("lex error : %s\n", yytext); return 0; }

%%