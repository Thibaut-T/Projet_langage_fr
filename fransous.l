%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "fransous.bison.hpp"
%}

%%

afficher|Afficher|AFFICHER {return print};
choix|Choix|CHOIX {return swicth};


%%
