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
fin[" "]choix|FIN[" "]CHOIX|Fin[""]Choix {return ENDSWITCH;}
reste|Reste|RESTE {return DEFAULT;}
cas|Cas|CAS { return CASE;}
fin[" "]cas|FIN[" "]CAS|Fin[" "]Cas { return BREAK;}
Tant[" "]que|TANT[" "]QUE|tant[" "]que {return WHILE;}
Fin[" "]tant[" "]que|FIN[" "]TANT[" "]QUE|fin[" "]tant[" "]que {return ENDWHILE;}
faire|Faire|FAIRE {return DO;}
fin[" "]faire|Fin[" "]Faire|FIN[" "]FAIRE {return ENDDO;}
si|SI|Si     { return IF; }
alors|ALORS|Alors   { return THEN; }
sinon|Sinon|SINON   { return ELSE; }
fin[" "]du[" "]si|FIN[" "]DU[" "]SI|Fin[" "]du[" "]si|Fin[" "]Du[" "]Si  { return ENDIF; }
pour|POUR|Pour { return FOR;}
Pour[" "]tout[" "]elements[" "]de|Pour[" "]Tout[" "]Elements[" "]De|POUR[" "]TOUT[" "]ELEMENTS[" "]DE {return FOREACH;}
fin[" "]du[" "]pour|FIN[" "]DU[" "]POUR|Fin[" "]Du[" "]Pour { return ENDFOR;}
entre {return BETWEEN;}
et {return AND;}
on[" "]ajoute {return INCR;}
on[" "]enleve {return DECR;}
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN; }
exp|Exp|EXP {return EXP;};
racine|Racine|RACINE {return SQRT;};
carre|Carre|CARRE {return POW;};
Ouvrir[" "]en[" "]lecture|OUVRIR[" "]EN[" "]LECTURE|ouvrir[" "]en[" "]lecture { return OPENFR;};
Ouvrir[" "]en[" "]ecriture|OUVRIR[" "]EN[" "]ECRITURE|ouvrir[" "]en[" "]ecriture { return OPENFW;};
supprimer|Supprimer|SUPPRIMER {return SUPPR;};
renommer|Renommer|RENOMMER {return NEWNAME;};
minuscule|Minuscule|MINUSCULE {return TOLOWER;};
en {return EN;};
dans {return DANS;};
jusque {return JUSQUE;};
premier|Premier|PREMIER {return FIRST;};
dernier|Dernier|DERNIER {return LAST;};
taille|Taille|TAILLE {return SIZE;};
Attendre|attendre|ATTENDRE {return WAIT;};
de {return DE;};
: { return SEPARATOR;}
"<"|inferieur|Inferieur {return INF;}
">"|superieur|Superieur {return SUP;}
"<="|inferieur[" "]ou[" "]egal|Inferieur[" "]ou[" "]egal|Inferieur[" "]Ou[" "]Egal {return INFEG; }
">="|superieur[" "]ou[" "]egal|Superieur[" "]ou[" "]Egal|superieur[" "]Ou[" "]Egal {return SUPEG; }
"!="|different|Different {return DIFF; }
"=="|egal|Egal {return EGAL; }
incrementer|Incrementer|INCREMENTER {return INCREMENTER;}
decrementer|Decrementer|DECREMENTER {return DECREMENTER;}
\(     {  return '('; }
\)     {  return ')'; }
vrai {return VRAI;}
faux {return FAUX;}

[A-Za-z_][A-Za-z_0-9]* { 
                         strcpy( yylval.nom, yytext) ;
                         return VAR;
                       }


\"[A-Za-z_][A-Za-z_0-9]*\" {strcpy( yylval.nom, yytext) ;
                         return VARAPO;}

[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? { // s'il s'agit d'un nombre on le stocke dans le champ "valeur"
                                      yylval.valeur = atof(yytext);
                                      return NUM;
                                    }

"+"|plus    { return ADD; }
"-"|moins   { return SUB; }
"*"|fois    { return MULT; }
"/"|divise  { return DIV; } /*Peut-être penser à un autre nom pour l'opérateur*/


"="|"<-"|"est"    {  return '='; }
"," {return ',';}
  

<<EOF>> { printf ("Le programme est correct.\n"); return 0;}
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
