%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <string>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  // Déclaration de la map qui associe
  // les noms des variables à leur valeur
  map<string,double> variables ;

%}

%union {
  double valeur;
  char nom[50];
}

%token classe
%token <valeur> NUM
%token <nom> VAR
%type <valeur> expr 
%token SIN
%token COS

%left '+' '-'
%left '*' '/'

%%
ligne:  /* Epsilon */
     | ligne instruction '\n'   

instruction : expr         { printf("Résultat du calcul : %g\n", $1); }
            | VAR '=' expr { variables[$1]=$3;  
                             printf ("Affectation de %g à %s\n", $3, $1);
                           }

expr:  NUM               { $$ = $1; }
     | VAR               { try { 
                                  $$ = variables.at($1);
                               }
                           catch(...){
                               printf ("La variable %s est utilisée mais jamais initialisée\n",$1);
                               variables[$1]=0;
                               $$ = 0.;
                               } 
                          }
     | SIN '(' expr ')'  { $$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ ); }
     | COS '(' expr ')'  { $$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ ); }
     | '(' expr ')'      { $$ = $2; }
     | expr '+' expr     { $$ = $1 + $3; printf ("%g + %g = %g\n", $1, $3, $$ );}
     | expr '-' expr     { $$ = $1 - $3; printf ("%g - %g = %g\n", $1, $3, $$ );}   		
     | expr '*' expr     { $$ = $1 * $3; printf ("%g * %g = %g\n", $1, $3, $$ );}		
     | expr '/' expr     { $$ = $1 / $3; printf ("%g / %g = %g\n", $1, $3, $$ );}    
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

int main(int argc, char **argv) {
  printf("Calculette V1.0\n");

  // Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();						

  return 0;
}