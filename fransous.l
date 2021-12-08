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
fin[" "]de[" "]ligne|Fin[" "]De[" "]Ligne|FIN[" "]DE[" "]LIGNE {return ENDL;}
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
pour[" "]tous[" "]éléments|Pour[" "]Tous[" "]Eléments|POUR[" "]TOUS[" "]ELEMENTS {return FOREACH;}
pour|POUR|Pour { return FOR;}
fin[" "]du[" "]pour|FIN[" "]DU[" "]POUR|Fin[" "]Du[" "]Pour { return ENDFOR;}
entre {return BETWEEN;}

on[" "]ajoute {return INCR;}
on[" "]enlève {return DECR;}
Sin|SIN|sin|sinus|Sinus|SINUS { return SIN;  }
Cos|COS|cos|cosinus|Cosinus|COSINUS { return COS;  }
Tan|TAN|tan|tangente|Tangente|TANGENTE { return TAN; }
exp|Exp|EXP {return EXP;};
racine|Racine|RACINE {return SQRT;};
puissance|Puissance|PUISSANCE {return POW;};
supprimer|Supprimer|SUPPRIMER {return SUPPR;};
mettre[" "]en[" "]minuscule|Mettre[" "]En[" "]Minuscule|METTRE[" "]EN[" "]MINUSCULE {return TOLOWER;};
mettre[" "]en[" "]majuscule|Mettre[" "]En[" "]Majuscule|METTRE[" "]EN[" "]MAJUSCULE  {return UPPER;}
en {return EN;};
dans {return DANS;};
jusque {return JUSQUE;};
premier[" "]élément[" "]de|Premier[" "]Elément[" "]De|PREMIER[" "]ELEMENT[" "]DE {return FIRST;};
dernier[" "]élément[" "]de|Dernier[" "]Elément[" "]De|DERNIER[" "]ELEMENT[" "]DE {return LAST;};
taille[" "]de|Taille[" "]De|TAILLE[" "]DE {return SIZE;};
de {return DE;};
: { return SEPARATOR;}
"<"|inférieur|Inférieur {return INF;}
">"|supérieur|Supérieur {return SUP;}
"<="|inférieur[" "]ou[" "]égal|Inférieur[" "]ou[" "]égal|Inférieur[" "]Ou[" "]Egal {return INFEG; }
">="|supérieur[" "]ou[" "]égal|Supérieur[" "]ou[" "]égal|supérieur[" "]Ou[" "]Egal {return SUPEG; }
"!="|différent|Différent {return DIFF; }
"=="|égal|Egal {return EGAL; }
ou[" "]que|Ou[" "]Que|OU[" "]QUE {return ORCOND;}
et[" "]que|Et[" "]Que|ET[" "]QUE { return ANDCOND;}
et {return AND;}

creer[" "]un[" "]tableau|Creer[" "]Un[" "]Tableau|CREER[" "]UN[" "]TABLEAU {return TAB;}
ajouter|Ajouter|AJOUTER { return TABADD;}
à|A {return A;}
élément[" "]numéro|Elément[" "]Numéro|ELEMENT[" "]NUMERO {return INDICE;}

incrementer|Incrementer|INCREMENTER {return INCREMENTER;}
decrementer|Decrementer|DECREMENTER {return DECREMENTER;}
concaténer|Concaténer|CONCATENER {return CONCAT;}


\(     {  return '('; }
\)     {  return ')'; }
vrai {return VRAI;}
faux {return FAUX;}

"+"|plus    { return ADD; }
"-"|moins   { return SUB; }
"*"|fois    { return MULT; }
"/"|diviser[" "]par  { return DIV; } /*Peut-être penser à un autre nom pour l'opérateur*/
"%"|modulo|MODULO|Modulo {return MOD;}


"="    {  return '='; }
"," {return ',';}
  
[A-Za-z_][A-Za-z_0-9]* { 
                         strcpy( yylval.nom, yytext) ;
                         return VAR;
                       }


\"([^\r\n\t\f\v]*?)\" {
                        strcpy( yylval.nom, yytext) ;
                        return VARAPO;}


[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? { // s'il s'agit d'un nombre on le stocke dans le champ "valeur"
                                      yylval.valeur = atof(yytext);
                                      return NUM;
                                    }

<<EOF>> { printf ("Le programme est correct.\n"); return 0;}
.      {  printf ("Erreur lexicale : %s\n", yytext); return 0; }

%%
