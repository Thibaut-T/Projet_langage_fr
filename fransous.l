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
si|SI|Si     { return IF; }
alors|ALORS|Alors   { return THEN; }
sinon|Sinon|SINON   { return ELSE; }
fin[" "]du[" "]si|FIN[" "]DU[" "]SI|Fin[" "]du[" "]si|Fin[" "]Du[" "]Si  { return ENDIF; }
repeter|REPETER|Repeter { return REPEAT; }
fin[" "]du[" "]repeter|FIN[" "]DU[" "]REPETER|Fin[" "]Du[" "]Repeter { return ENDREPEAT;}
pour|POUR|Pour { return FOR;}
fin[" "]du[" "]pour|FIN[" "]DU[" "]POUR|Fin[" "]Du[" "]Pour { return ENDFOR;}
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN; }
  

  <<EOF>> { printf ("Le programme est correct.\n"); return 0;}
.      {  printf ("lex error : %s\n", yytext); return 0; }

%%