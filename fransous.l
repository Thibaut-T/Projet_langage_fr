%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "fransous.bison.hpp"
%}

%%
"non" {return NON; }
\n     {  return '\n'; }
\r     { }
" "    { }
\t     { }

(\/\*)([\s\S]*?)(\*\/)|\/\/([\S\s]*?)\n  {return commentaire;}
afficher|Afficher|AFFICHER {return PRINT;}
choix|Choix|CHOIX {return SWITCH;}
fin[" "]choix|FIN[" "]SWITCH|Fin[""]Switch {return ENDSWITCH;}
cas|Cas|CAS { return CASE;}
fin[" "]cas|FIN[" "]CAS|Fin[" "]Cas { return BREAK;}
Tant[" "]que|TANT[" "]QUE|tant[" "]que {return WHILE;}
Fin[" "]tant|FIN[" "]TANT|fin[" "]tant {return ENDWHILE;}
si|SI|Si     { return IF; }
alors|ALORS|Alors   { return THEN; }
sinon|Sinon|SINON   { return ELSE; }
fin[" "]du[" "]si|FIN[" "]DU[" "]SI|Fin[" "]du[" "]si|Fin[" "]Du[" "]Si  { return ENDIF; }
pour|POUR|Pour { return FOR;}
fin[" "]du[" "]pour|FIN[" "]DU[" "]POUR|Fin[" "]Du[" "]Pour { return ENDFOR;}
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN; }
exp|Exp|EXP {return exp;};
racine|Racine|RACINE {return sqrt;};
carre|Carre|CARRE {return pow;};
Ouvrir[" "]en[" "]lecture|OUVRIR[" "]EN[" "]LECTURE|ouvrir[" "]en[" "]lecture { return openFileRead;};
Ouvrir[" "]en[" "]ecriture|OUVRIR[" "]EN[" "]ECRITURE|ouvrir[" "]en[" "]ecriture { return openFileWrite;};
supprimer|Supprimer|SUPPRIMER {return remove;};
renommer|Renommer|RENOMMER {return rename;};
minuscule|Minuscule|MINUSCULE {return tolower;};
en {return "en";};
dans {return "dans";};
jusque {return "jusque";};
premier|Premier|PREMIER {return first};
dernier|Dernier|DERNIER {return last};
taille|Taille|TAILLE {return size};
de {return de};

"<" {return INF;}
">" {return SUP;}
"<=" {return INFEG; }
">=" {return SUPEG; }
"!=" {return DIFF; }
"==" {return EGAL; }

: { return SEPARATOR;}
\(     {  return '('; }
\)     {  return ')'; }

  

  <<EOF>> { printf ("Le programme est correct.\n"); return 0;}
.      {  printf ("lex error : %s\n", yytext); return 0; }

%%